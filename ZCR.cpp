    #include<stdio.h>
    double dp[1003][1003], a[1003];
    double fn(int n, int k){
    	if(n<=0 && k>0){
    		return 0;
    	}
    	if(k<0){
    		return 0;
    	}
    	if(dp[n][k]==-1){
    		if(k>n){
    			dp[n][k]=0;
    		}
    		else{
    			dp[n][k]=((1-a[n])*fn(n-1, k))+(a[n]*fn(n-1, k-1));
    		}
    	}
    	return dp[n][k];
    }
    int main(){
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
     
    		for(int i=0;i<1003;i++){
    			for(int j=0;j<1003;j++){
    				dp[i][j]=-1;
    			}
    		}
    		dp[0][0]=1.0;
     
    		int n, k;
    		scanf("%d %d", &n, &k);
    		for(int i=1;i<=n;i++){
    			scanf("%lf", &a[i]);
    		}
     
    		printf("%0.10lf\n", fn(n, k));
     
    	}
    	return 0;
    } 