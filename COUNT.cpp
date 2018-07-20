    #include<stdio.h>
    using namespace std;
    int dp[5005][5005], m=1988;
    int fn(int n, int k){
    	if(n<0 || k<0){
    		return 0;	
    	}
    	if(dp[n][k]==-1){
    		if(k==1 && n>=1){
    			dp[n][k]=1;
    		}
    		else if(k>n){
    			dp[n][k]=0;
    		}
    		else if(n==k){
    			dp[n][k]=1;
    		}
    		else{
    			dp[n][k]=0;
    			for(int i=0;i<=k;i++){
    				dp[n][k]=(dp[n][k]+fn(n-k, k-i))%m;
    			}
    		}
    	}
    	return dp[n][k];
    }
    int main(){
    	for(int i=0;i<5005;i++){
    		for(int j=0;j<5005;j++){
    			dp[i][j]=-1;
    		}
    	}
    	int n, k;
    	while(1){
    		scanf("%d %d", &n, &k);
    		if(n==0 && k==0){
    			break;
    		}
    		printf("%d\n", fn(n, k));
    	}
    	return 0;
    } 
