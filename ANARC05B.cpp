    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> a, b, inda, indb;
    vector<int>:: iterator it;
    long long dp[2][10004];
    long long fn(int ch, int ind){
    	if(dp[ch][ind]==-1){
    		if(ch==0){
    			if(ind>=a.size()){
    				dp[ch][ind]=0;
    			}
    			else{
    				if(inda[ind]==-1){
    					dp[ch][ind]=a[ind]+fn(0, ind+1);
    				}
    				else{
    					dp[ch][ind]=a[ind]+max(fn(0, ind+1), fn(1, inda[ind]+1));
    				}
    			}
    		}	
    		else{
    			if(ind>=b.size()){
    				dp[ch][ind]=0;
    			}
    			else{
    				if(indb[ind]==-1){
    					dp[ch][ind]=b[ind]+fn(1, ind+1);
    				}
    				else{
    					dp[ch][ind]=b[ind]+max(fn(1, ind+1), fn(0, indb[ind]+1));	
    				}
    			}
    		}
    	}
    	return dp[ch][ind];	
    }
    int main(){
    	while(1){
    		
    		for(int i=0;i<2;i++){
    			for(int j=0;j<10004;j++){
    				dp[i][j]=-1;
    			}
    		}
     
    		a.clear();b.clear();inda.clear();indb.clear();
    		int n1, n2, temp;
    		scanf("%d", &n1);
    		if(n1==0){
    			break;
    		}
    		for(int i=0;i<n1;i++){
    			scanf("%d", &temp);
    			a.push_back(temp);
    			inda.push_back(-1);
    		}
    		scanf("%d", &n2);
    		for(int i=0;i<n2;i++){
    			scanf("%d", &temp);
    			b.push_back(temp);
    			indb.push_back(-1);
    		}
     
    		for(int i=0;i<n1;i++){
    			it=lower_bound(b.begin(), b.end(), a[i]);
    			if(b[it-b.begin()]==a[i]){
    				inda[i]=it-b.begin();
    				indb[it-b.begin()]=i;
    			}
    		}
     
    		printf("%lld\n", max(fn(0, 0), fn(1, 0)));		
     
    	}
    	return 0;
    } 
