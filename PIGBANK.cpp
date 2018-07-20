    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long dp[10004][505];
    long long int value[505];
    long long int weight[505];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long int E, F, W, k;
    		scanf("%lld %lld", &E, &F);
    		W=F-E;;
    		scanf("%lld", &k);
    		for(long long int i=1;i<=k;i++){
    			scanf("%lld", &value[i]);
    			scanf("%lld", &weight[i]);
    		}
     
    		for(long long int i=0;i<=k;i++){
    			dp[0][i]=0;
    		}
    		for(long long int i=1;i<=W;i++){
    			dp[i][0]=-1;
    		}
     
    		for(long long int i=1;i<=W;i++){
    			for(long long int j=1;j<=k;j++){
    				if(i-weight[j]<0){
    					dp[i][j]=dp[i][j-1];
    				}
    				else{
    					if(dp[i][j-1]<0 && dp[i-weight[j]][j]<0){
    						dp[i][j]=-1;
    					}
    					else if(dp[i][j-1]<0){
    						dp[i][j]=dp[i-weight[j]][j]+value[j];
    					}
    					else if(dp[i-weight[j]][j]<0){
    						dp[i][j]=dp[i][j-1];
    					}
    					else{
    						dp[i][j]=min(dp[i][j-1], dp[i-weight[j]][j]+value[j]);
    					}
    				}
    			}
    		}
     
    		/*for(long long i=1;i<=W;i++){
    			printf("%lld ", i);
    			for(long long  j=1;j<=k;j++){
    				printf("%lld ", dp[i][j]);
    			}
    			printf("\n");
    		}*/
     
    		long long ans=1000000000000;
    		for(long long int i=0;i<=k;i++){
    			if(dp[W][i]<ans && dp[W][i]!=-1){
    				ans=dp[W][i];
    			}
    		}
    		if(ans==1000000000000){
    			printf("This is impossible.\n");
    		}
    		else{
    			printf("The minimum amount of money in the piggy-bank is %lld.\n", ans);
    		}
    	}
    	return 0;
    } 
