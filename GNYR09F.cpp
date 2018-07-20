    #include<stdio.h>
    #include<string.h>
    using namespace std;
    long long rec[102];
    char a[2005];
    long long dp[102][102];
    long long fib(int n){
    	if(rec[n]==-1){
    		if(n==0){
    			rec[n]=1;
    		}
    		else if(n==1){
    			rec[n]=2;
    		}
    		else{
    			rec[n]=fib(n-1)+fib(n-2);
    		}
    	}
    	return rec[n];
    }
    long long fn(int n, int k){
    	if(dp[n][k]==-1){
    		if(k==0){
    			dp[n][k]=fib(n);
    		}
    		else if(n==k+1){
    			dp[n][k]=1;
    		}
    		else if(n<=k){
    			dp[n][k]=0;
    		}
    		else{
    			long long partial=0;
    			partial+=fn(n-1, k);
    			for(int i=1;i<=k+1;i++){
    				partial+=fn(n-1-i, k-i+1);
    			}
    			dp[n][k]=partial;	
    		}
    	}
    	// printf("(%d, %d)->%lld\n", n, k, dp[n][k]);
    	return dp[n][k];
    }
    int main(){
     
    	for(int i=0;i<102;i++){
    		for(int j=0;j<102;j++){
    			dp[i][j]=-1;
    		}
    		rec[i]=-1;
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int t, n, k;
    		scanf("%d %d %d", &t, &n, &k);
     
    		printf("%d %lld\n", t, fn(n, k));
     
    	}
    	return 0;
    } 
