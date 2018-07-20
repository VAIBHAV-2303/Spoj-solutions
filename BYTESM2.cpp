    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int mat[105][105];
    int dp[105][105];
    int n, m;
    int fn(int i, int j){
    	if(i>=n || j>=m || i<0 || j<0){
    			return 0;
    	}
    	
    	if(dp[i][j]==-1){
    		 dp[i][j]=mat[i][j]+max(fn(i+1, j-1), max(fn(i+1, j), fn(i+1, j+1)));
    	}
    	return dp[i][j];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%d %d", &n, &m);
    		int curmax=-1;
    		for(int i=0;i<n;i++){
    			for(int j=0;j<m;j++){
    				scanf("%d", &mat[i][j]);
    			}
    		}
     
    		for(int i=0;i<105;i++){
    			for(int j=0;j<105;j++){
    				dp[i][j]=-1;
    			}
    		}
     
    		for(int i=0;i<m;i++){
    			if(fn(0, i)>curmax){
    				curmax=fn(0, i);
    			}
    		}
     
    		printf("%d\n", curmax);
     
    	}
    	return 0;
    } 
