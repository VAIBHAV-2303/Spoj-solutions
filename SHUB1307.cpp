    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int dp[103][103][503], a[103][103], n, m;
    int fn(int i, int j, int k){
    	// printf("%d %d %d\n", i, j, k);
    	if(dp[i][j][k]==-20000000){
    		if(i==n && j==m){
    			if(a[n][m]>k){
    				dp[i][j][k]=-10000000;
    			}
    			else{
    				dp[i][j][k]=a[n][m];
    			}
    		}
    		else if(i==n){
    			if(a[i][j]>k){
    				dp[i][j][k]=-10000000;
    			}
    			else{
    				dp[i][j][k]=a[i][j]+fn(i, j+1, k-a[i][j]);
    			}
    		}
    		else if(j==m){
    			if(a[i][j]>k){
    				dp[i][j][k]=-10000000;
    			}
    			else{
    				dp[i][j][k]=a[i][j]+fn(i+1, j, k-a[i][j]);
    			}
    		}
    		else{
    			if(a[i][j]>k){
    				dp[i][j][k]=-10000000;
    			}
    			else{
    				dp[i][j][k]=a[i][j]+max(fn(i+1, j, k-a[i][j]), max(fn(i, j+1, k-a[i][j]), fn(i+1, j+1, k-a[i][j])));
    			}
    		}
    	}
    	return dp[i][j][k];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int k;
    		scanf("%d %d %d", &n, &m, &k);
     
    		for(int i=0;i<n+3;i++){
    			for(int j=0;j<m+3;j++){
    				for(int u=0;u<k+3;u++){
    					dp[i][j][u]=-20000000;
    				}
    			}
    		}
     
    		for(int i=0;i<n;i++){
    			for(int j=0;j<m;j++){
    				scanf("%d", &a[i][j]);
    			}
    		}
     
    		n--;
    		m--;
     
    		printf("%d\n", max(fn(0, 0, k), -1));
     
    	}
    	return 0;
    } 