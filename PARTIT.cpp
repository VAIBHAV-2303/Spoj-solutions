    #include<bits/stdc++.h>
    using namespace std;
    long long dp[221][11][221];
    long long fn(int m, int n, int cur){
    	if(dp[m][n][cur]==-1){
    		if(m<cur){
    			dp[m][n][cur]=0;
    		}
    		else if(n==1){
    			dp[m][n][cur]=1;
    		}
    		else{
    			dp[m][n][cur]=0;
    			for(int i=cur;i<=(m/2);i++){
    				dp[m][n][cur]+=fn(m-i, n-1, i);
    			}
    		}
    	}
    	return dp[m][n][cur];
    }
    int main(){
     
    	for(int i=0;i<221;i++){
    		for(int j=0;j<11;j++){
    			for(int k=0;k<221;k++){
    				dp[i][j][k]=-1;
    			}
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int m, n, cur=1;
    		long long k;
    		scanf("%d %d %lld", &m, &n, &k);
    		
    		for(int i=1;i<n;i++){
    			while(fn(m-cur, n-i, cur)<k){
    				k-=fn(m-cur, n-i, cur);
    				cur++;
    			}
    			printf("%d ", cur);
    			m-=cur;
    		}
    		printf("%d\n", m);	
    	}
    	return 0;
    } 