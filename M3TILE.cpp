    #include<bits/stdc++.h>
    using namespace std;
    long long int dp[35]={0};
    long long fn(int n){
    	if(n<0){
    		return 0;
    	}
    	if(dp[n]==0){
    		if(n==0){
    			dp[n]=1;
    		}
    		else if(n==1){
    			dp[n]=0;
    		}
    		else if(n==2){
    			dp[n]=3;	
    		}
    		else{
    			dp[n]=3*fn(n-2);
    			for(int i=4;i<=n;i+=2){
    				dp[n]+=2*fn(n-i);
    			}
    		}
    	}
    	return dp[n];
    }
    int main(){
    	int n;
    	while(1){
    		scanf("%d", &n);
    		if(n==-1){
    			break;
    		}
     
    		printf("%lld\n", fn(n));
     
    	}
    	return 0;
    }
     