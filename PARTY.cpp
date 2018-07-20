    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int fun;
    	int price;
    }node;
    node dp[505][105];
    int fun[105];
    int price[105];
    int main(){
    	int budget, k;
    	while(1){
    		scanf("%d %d", &budget, &k);
    		if(budget==0 && k==0){
    			return 0;
    		}
    		for(int i=1;i<=k;i++){
    			scanf("%d", &price[i]);
    			scanf("%d", &fun[i]);
    		}
     
    		for(int i=0;i<=k;i++){
    			dp[0][i].fun=0;
    			dp[0][i].price=0;
    		}
    		for(int i=0;i<=budget;i++){
    			dp[i][0].fun=0;
    			dp[i][0].price=0;
    		}
     
    		for(int i=1;i<=budget;i++){
    			for(int j=1;j<=k;j++){
    				if(i-price[j]<0){
    					dp[i][j].fun=dp[i][j-1].fun;
    					dp[i][j].price=dp[i][j-1].price;
    				}
    				else{
    					if(dp[i][j-1].fun>dp[i-price[j]][j-1].fun+fun[j]){
    						dp[i][j]=dp[i][j-1];
    					}
    					else if(dp[i][j-1].fun<dp[i-price[j]][j-1].fun+fun[j]){
    						dp[i][j].fun=dp[i-price[j]][j-1].fun+fun[j];
    						dp[i][j].price=dp[i-price[j]][j-1].price+price[j];
    					}
    					else{
    						dp[i][j].fun=dp[i-price[j]][j-1].fun+fun[j];	
    						if(dp[i][j-1].price<=dp[i-price[j]][j-1].price+price[j]){
    							dp[i][j].price=dp[i][j-1].price;
    						}
    						else{
    							dp[i][j].price=dp[i-price[j]][j-1].price+price[j];		
    						}
    					}
    				}
    			}
    		}
     
    		/*for(int i=1;i<=budget;i++){
    			printf("%d ", i);
    			for(int j=1;j<=k;j++){
    				printf("%d ", dp[i][j].fun);
    			}
    			printf("\n");
    		}*/
     
    		printf("%d %d\n", dp[budget][k].price, dp[budget][k].fun);
    	}
    } 
