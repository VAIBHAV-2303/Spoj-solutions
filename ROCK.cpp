    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    char s[203];
    int dp[203];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, count, maxm;
    		scanf("%d", &n);
    		scanf("%s", s);
    		
    		for(int i=0;i<n;i++){
    			count=0, maxm=0;
    			for(int j=i;j>=0;j--){
    				if(s[j]=='1'){
    					count++;
    				}
    				else{
    					count--;
    				}
     
    				if(j==0){
    					if(count>0){
    						if(i-j+1>maxm){
    							maxm=i-j+1;
    						}
    					}
    				}
    				else{
    					if(count>0){
    						if(i-j+1+dp[j-1]>maxm){
    							maxm=i-j+1+dp[j-1];
    						}
    					}
    				}
    			}
    			dp[i]=max(maxm, dp[i-1]);
    		}
    		/*for(int i=0;i<n;++i){
    			printf("%d", dp[i]);
    		}
    		printf("\n");*/
    		printf("%d\n", dp[n-1]);
    	}
    	return 0;
    } 
