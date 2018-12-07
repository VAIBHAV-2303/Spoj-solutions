    #include<bits/stdc++.h>
    using namespace std;
    long long int dp[32775][64][74];
    long long int fn(int n, int h, int m){
    	if(n<=0){
    		return 0;
    	}
    	if(dp[n][h][m]==-1){	
    		if(h==1){
    			if(n<m-1){
    				dp[n][h][m]=0;
    			}
    			else if(n<m+1){
    				if(m>=2){
    					dp[n][h][m]=1;
    				}
    				else{
    					dp[n][h][m]=0;
    				}
    			}
    			else{
    				if(m>=2){
    					dp[n][h][m]=2;
    				}
    				else{
    					dp[n][h][m]=1;
    				}
    			}
    		}
    		else{
    			if(n<m-1){
    				dp[n][h][m]=0;
    			}
    			else if(n<m+1){
    				if(m>=2){
    					dp[n][h][m]=fn(n-(m-1), h-1, m-1);
    				}
    				else{
    					dp[n][h][m]=0;		
    				}
    			}
    			else{
    				if(m>=2){
    					dp[n][h][m]=fn(n-(m-1), h-1, m-1) + fn(n-(m+1), h-1, m+1);
    				}
    				else{
    					dp[n][h][m]=fn(n-(m+1), h-1, m+1);	
    				}
    			}	
    		}
    	}	
    	return dp[n][h][m];
    }
    int main(){
    	for(int i=0;i<32775;i++){
    		for(int j=0;j<64;j++){
    			for(int k=0;k<74;k++){
    				dp[i][j][k]=-1;
    			}
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, h, m;
    		scanf("%d %d %d", &n, &h, &m);
     
    		if(h==1){
    			if(m>n){
    				printf("0\n");
    			}
    			else{
    				printf("1\n");
    			}
    			continue;
    		}
    		printf("%lld\n", fn(n-m, h-1, m));
    	}
    	return 0;
    } 