    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    char a[20];
    vector<char> ans;
    void maxfn(int ind, int l, int k){
    	if(l-ind <= k || ind>=l){
    		return;
    	}
     
    	int curmax=-1, ansind;
    	for(int i=ind;i<=ind+k;i++){
    		if((int)(a[i]-'0')>curmax){
    			curmax=(int)(a[i]-'0');
    			ansind=i;
    		}
    	}
     
    	ans.push_back(a[ansind]);
    	return maxfn(ansind+1, l, k-ansind+ind);
    }
    void minfn(int ind, int l, int k){
    	if(l-ind <= k || ind>=l){
    		return;
    	}
     
    	int curmin=10, ansind;
    	for(int i=ind;i<=ind+k;i++){
    		if((int)(a[i]-'0')<curmin){
    			curmin=(int)(a[i]-'0');
    			ansind=i;
    		}
    	}
     
    	ans.push_back(a[ansind]);
    	return minfn(ansind+1, l, k-ansind+ind);
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int q, n, k; 
    		scanf("%s %d", a, &q);
    		n=strlen(a);
    		printf("Case %d:\n", t);
    		while(q--){
    			ans.clear();
    			scanf("%d", &k);
    			maxfn(0, n, k);
    			if(ans.size()==0){
    				printf("0");
    			}
    			else{
    				int ind=0;
    				while(ind<ans.size() && ans[ind]=='0'){
    					ind++;
    				}
    				if(ind==ans.size()){
    					printf("0");
    				}
    				else{
    					for(int i=ind;i<ans.size();i++){
    						printf("%c", ans[i]);
    					}
    				}	
    			}
    	
    			printf(" ");
     
    			ans.clear();
    			minfn(0, n, k);
    			if(ans.size()==0){
    				printf("0");
    			}
    			else{
    				int ind=0;
    				while(ind<ans.size() && ans[ind]=='0'){
    					ind++;
    				}
    				if(ind==ans.size()){
    					printf("0");
    				}
    				else{
    					for(int i=ind;i<ans.size();i++){
    						printf("%c", ans[i]);
    					}
    				}
    			}
    			printf("\n");
    		}
    	}
    	return 0;
    } 
