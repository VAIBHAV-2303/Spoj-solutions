    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long dp[10004];
    long long a[10004];
    int n;
    long long fn(int ind){
    	if(dp[ind]==-1){
    		if(ind>=n){
    			dp[ind]=0;
    		}
    		else if(ind==n-1){
    			dp[ind]=a[ind];
    		}
    		else{
    			dp[ind]=max(a[ind]+fn(ind+2), fn(ind+1));
    		}
    	}
    	return dp[ind];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		scanf("%d", &n);
    		for(int i=0;i<10004;i++){
    			dp[i]=-1;
    		}
    		for(int i=0;i<n;i++){
    			scanf("%lld", &a[i]);
    		}
     
    		printf("Case %d: %lld\n", t, fn(0));
    	}
    	return 0;
    }  
