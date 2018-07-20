    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long west[502][502];
    long long north[502][502];
    long long dp[502][502];
    int n, m;
    long long fn(int x, int y){
    	if(dp[x][y]==-1){
    		if(x==0 || y==0){
    			dp[x][y]=0;
    			// printf("pui\n");
    		}
    		else{
    			long long partial1=0, partial2=0;
    			for(int i=n-x;i<n;i++){
    				partial1+=west[i][m-y];
    			}
    			// printf("%lld\n", partial1);
    			for(int i=m-y;i<m;i++){
    				partial2+=north[n-x][i];
    			}
    			dp[x][y]=max(partial1+fn(x, y-1), partial2+fn(x-1, y));
    		}
    	}
    	return dp[x][y];
    }
    int main(){
    	while(1){
    		scanf("%d %d", &n, &m);
    		if(n==0 && m==0){
    			break;
    		}
     
    		for(int i=0;i<n;i++){
    			for(int j=0;j<m;j++){
    				scanf("%lld", &west[i][j]);
    			}	
    		}
     
    		for(int i=0;i<n;i++){
    			for(int j=0;j<m;j++){
    				scanf("%lld", &north[i][j]);
    			}	
    		}
     
    		for(int i=0;i<=n;i++){
    			for(int j=0;j<=m;j++){
    				dp[i][j]=-1;
    			}
    		}
    		// printf("pui\n");
    		printf("%lld\n", fn(n, m));
     
    	}
    	return 0;
    } 
