    #include<stdio.h>
    using namespace std;
    int a[102];
    long long dp[102][102];
    int sum(int i, int j){
    	int partial=0;
    	for(int t=i;t<=j;t++){
    		partial=(partial+a[t])%100;
    	}
    	return partial;
    }
    long long fn(int i, int j){
    	if(dp[i][j]==-1){
    		long long curmin=100000000000000;
    		if(j==i){
    			dp[i][j]=0;
    			return dp[i][j];
    		}
    		for(int t=i;t<j;t++){
    			if(fn(i, t)+fn(t+1, j)+sum(i, t)*sum(t+1, j)<curmin){
    				curmin=fn(i, t)+fn(t+1, j)+(sum(i, t)*sum(t+1, j));
    			}
    		}
    		dp[i][j]=curmin;
    	}
    	return dp[i][j];
    }
    int main(){
    	int n;
    	while(scanf("%d", &n)!=EOF){
    		for(int i=0;i<=100;i++){
    			for(int j=0;j<=100;j++){
    				dp[i][j]=-1;
    			}
    		}
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		fn(0, n-1);
    		printf("%lld\n", dp[0][n-1]);
    	}
    	return 0;
    } 
