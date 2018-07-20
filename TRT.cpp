    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long ar[2005];
    long long dp[2005][2005];
    long long fn(int i, int j, int a){
    	if(dp[i][j]==-1){
    		if(i==j){
    			dp[i][j]=a*ar[i];
    		}
    		else{
    			dp[i][j]=max(a*ar[j]+fn(i, j-1, a+1), a*ar[i]+fn(i+1, j, a+1));
    		}
    	}
     
    	return dp[i][j];
    }
    int main() {
    	int n;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%lld", &ar[i]);
    	}
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			dp[i][j]=-1;
    		}
    	}
     
    	printf("%lld\n", fn(0, n-1, 1));
     
    	return 0;
    }  
