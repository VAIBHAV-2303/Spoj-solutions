    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Cyl{
    	long long ox;
    	long long ni;
    	long long weight;
    }cyl;
    cyl data[1001];
    long long dp[22][80][1001];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		for(long long i=0;i<22;i++){
    			for(long long j=1;j<80;j++){
    				dp[i][j][0]=10000000000000000;
    			}
    		}
     
    		for(long long i=0;i<80;i++){
    			for(long long j=1;j<22;j++){
    				dp[j][i][0]=1000000000000000;
    			}
    		}
     
    		long long O, N;
    		scanf("%lld %lld", &O, &N);
    		long long n;
    		scanf("%lld", &n);
    		for(long long i=1;i<=n;i++){
    			scanf("%lld %lld %lld", &data[i].ox, &data[i].ni, &data[i].weight);
    		}
    		// printf("pui\n");
    		for(long long i=0;i<=O;i++){
    			for(long long j=0;j<=N;j++){
    				for(long long k=1;k<=n;k++){
    					if(i==0 && j==0){
    						dp[i][j][k]=0;
    					}
    					if(i-data[k].ox<0 || j-data[k].ni<0){
    						if(i<=data[k].ox && j<=data[k].ni){
    							dp[i][j][k]=min(dp[i][j][k-1], data[k].weight);
    						}
    						else{
    							if(j<=data[k].ni){
    								dp[i][j][k]=min(dp[i][j][k-1], dp[i-data[k].ox][j][k-1]+data[k].weight);
    							}
    							else{
    								dp[i][j][k]=min(dp[i][j][k-1], dp[i][j-data[k].ni][k-1]+data[k].weight);	
    							}
    						}
    					}
    					else{
    						dp[i][j][k]=min(dp[i][j][k-1], dp[i-data[k].ox][j-data[k].ni][k-1]+data[k].weight);
    					}
    				}
    			}
    		}
     
    		/*for(int i=0;i<=N;i++){
    			for(int k=0;k<=n;k++){
    				printf("%lld ", dp[0][i][k]);
    			}
    			printf("\n");
    		}*/
     
    		printf("%lld\n", dp[O][N][n]);
    	}
     
    	return 0;
    } 
