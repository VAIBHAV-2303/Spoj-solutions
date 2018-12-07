    #include<stdio.h>
    int dp[1003], m=1908;
    int fn(int n){
    	if(dp[n]==-1){
    		if(n==0){
    			dp[n]=1;
    		}
    		else if(n==1){
    			dp[n]=1;
    		}
    		else{
    			dp[n]=0;
    			for(int i=1;i<=n;i++){
    				dp[n]=(dp[n] + ((fn(i-1)*fn(n-i))%m) )%m;
    			}
    		}
    	}
    	return dp[n];
    }
    int main(){
     
    	for(int i=0;i<1003;i++){
    		dp[i]=-1;
    	}
     
    	int T;
    	scanf("%d", &T);
     
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		printf("%d\n", fn(n));
    	}
    	return 0;
    } 