    #include<stdio.h>
    int dp[1003][1003], m=1e9+7;
    int fn(int n, int k){
    	if(dp[n][k]==-1){
    		if(n==k){
    			dp[n][k]=1;
    		}
    		else if(k>n){
    			dp[n][k]=0;
    		}
    		else{
    			dp[n][k]=(fn(n-k, k)+fn(n, k+1))%m;
    		}
    	}
    	return dp[n][k];
    }
    int main(){
     
    	for(int i=0;i<1003;i++){
    		for(int j=0;j<1003;j++){
    			dp[i][j]=-1;
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, k;
    		scanf("%d %d", &n, &k);
    		printf("%d\n", fn(n, k));
    	}
    	return 0;
    } 