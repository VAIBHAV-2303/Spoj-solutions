    #include<stdio.h>
    using namespace std;
    long long dp[15][100][15];
    long long fn(int terms, int req, int mx){
    	if(req<0 || terms<0){
    		return 0;
    	}
    	if(terms==1){
    		if(mx>=req){
    			return 1;
    		}
    		else{
    			return 0;
    		}
    	}
    	else{
    		if(dp[terms][req][mx]==-1){
    			long long int partial=0;
    			for(int i=0;i<=mx;i++){
    				partial+=fn(terms-1, req-i, mx+1);
    			}
    			dp[terms][req][mx]=partial;
    		}
    		return dp[terms][req][mx];
    	}
    }
    int main(){
    	for(int i=0;i<15;i++){
    		for(int j=0;j<100;j++){
    			for(int k=0;k<15;k++){
    				dp[i][j][k]=-1;
    			}
    		}
    	}
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, k;
    		scanf("%d %d", &n, &k);
    		if(k==0){
    			printf("1\n");
    			continue;
    		}
    		printf("%lld\n", fn(n-1, k, 1));
    	}
    	return 0;
    } 
