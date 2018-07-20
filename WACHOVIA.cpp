    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int weight;
    	int value;
    }node;
    node a[55];
    int dp[1005][55];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int W, n;
    		scanf("%d %d", &W, &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d %d", &a[i].weight, &a[i].value);
    		}
     
    		for(int i=0;i<=n;i++){
    			dp[0][i]=0;
    		}
    		for(int i=0;i<=W;i++){
    			dp[i][0]=0;
    		}
     
     
    		for(int i=1;i<=W;i++){
    			for(int j=1;j<=n;j++){
    				if(i-a[j].weight<0){
    					dp[i][j]=dp[i][j-1];
    				}
    				else{
    					dp[i][j]=max(dp[i][j-1], dp[i-a[j].weight][j-1]+a[j].value);
    				}
    			}
    		}
     
    		printf("Hey stupid robber, you can get %d.\n", dp[W][n]);
     
    	}
    	return 0;
    } 
