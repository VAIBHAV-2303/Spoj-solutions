    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long dp[11][66]={0};
    long long fn(int prev, int d){
    	if(dp[prev][d]==0){
    		if(d==1){
    			dp[prev][d]=10-prev;
    		}
    		else{
    			long long partial=0;
    			for(int i=prev;i<=9;i++){
    				partial+=fn(i, d-1);
    			}
    			dp[prev][d]=partial;
    		}
    	}
    	return dp[prev][d];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int t, n;
    		scanf("%d %d", &t, &n);
    		printf("%d %lld\n", t, fn(0, n));
    	}
    	return  0;
    }
     
