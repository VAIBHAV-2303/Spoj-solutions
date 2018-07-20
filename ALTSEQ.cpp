    #include<stdio.h>
    #include<math.h>
    #include<bits/stdc++.h>	
    using namespace std;
    int dp[5005];
    long long a[5005];
    int main(){
    	int n, maxi;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%lld", &a[i]);
    	}
     
    	dp[0]=1;
     
    	// printf("pui\n");
    	for(int i=1;i<n;i++){
    		maxi=0;
    		for(int j=i-1;j>=0;j--){
    			if(a[i]*a[j]<0 && dp[j]>maxi && abs(a[j])<abs(a[i])){
    				maxi=dp[j];
    			}
    		}
    		dp[i]=maxi+1;
    	}
    	maxi=0;
    	for(int i=0;i<n;i++){
    		if(dp[i]>maxi){
    			maxi=dp[i];
    		}
    	}
    	printf("%d\n", maxi);
     
    	return 0;
    } 
