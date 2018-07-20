    #include<stdio.h>
    #include<math.h>
    #include<bits/stdc++.h>
    using namespace std;
    int a[205];
    int dp[25005][205];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, y, x, total=0, rt;
    		scanf("%d", &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d %d", &x, &y);
    			a[i]=abs(x-y);
    			total+=a[i];
    		}
    		rt=total;
    		total=total/2;
    		for(int i=0;i<=n;i++){
    			dp[0][i]=0;
    		}
    		for(int i=0;i<=total;i++){
    			dp[i][0]=0;
    		}
     
    		// printf("pui\n");
    		for(int i=1;i<=total;i++){
    			for(int j=1;j<=n;j++){
    				if(i-a[j]<0){
    					dp[i][j]=dp[i][j-1];
    				}
    				else{
    					dp[i][j]=max(dp[i][j-1], dp[i-a[j]][j-1]+a[j]);
    				}
    			}
    		}
    		/*for(int i=1;i<=total;i++){
    			for(int j=1;j<=n;j++){
    				printf("%d ", dp[i][j]);
    			}
    			printf("\n");
    		}*/
    		printf("%d\n", rt-2*dp[total][n]);
     
    	}
    	return 0;
    } 
