    #include<bits/stdc++.h>
    using namespace std;
    int freq1[100005], freq2[100005];
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
     
    		for(int i=0;i<100005;i++){
    			freq1[i]=0;
    			freq2[i]=0;
    		}
     
    		int n, x;
    		scanf("%d", &n);
     
    		for(int i=0;i<n;i++){
    			scanf("%d", &x);
    			freq1[x]++;
    			freq2[x]++;
    		}
     
    		int cpointer=1;
     
    		for(int i=1;i<100005;i++){
    			if(cpointer>=100005){
    				break;
    			}
     
    			while(cpointer<(2*i)){
    				cpointer++;
    			}
     
    			while(freq1[i]!=0){
    				while(cpointer<100005 && freq2[cpointer]==0){
    					cpointer++;
    				}
    				if(cpointer==100005){
    					break;
    				}
     
    				if(freq1[i]>freq2[cpointer]){
    					freq1[i]-=freq2[cpointer];
    					freq2[cpointer]=0;
    				}
    				else{
    					freq2[cpointer]-=freq1[i];
    					freq1[i]=0;
    				}
    			}
    		}
    		int ans=0;
    		for(int i=0;i<100005;i++){
    			ans+=freq1[i];
    		}
    		printf("Case %d: %d\n", t, ans);
    	}
    	return 0;
    } 