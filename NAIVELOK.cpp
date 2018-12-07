    #include<bits/stdc++.h>
    using namespace std;
    #include<string.h>
    int m=1e9+7, dp[103][103];
    char a[103];
    int nCr(int n, int r){
    	if(r>n){
    		return 0;
    	}
     
    	if(dp[n][r]==0){
    		if(n==r || r==0){
    			dp[n][r]=1;
    		}
    		else{
    			dp[n][r]=(nCr(n-1, r)+nCr(n-1, r-1))%m;
    		}
    	}
    	return dp[n][r];
    }
    int power(int x, int y){
    	int res=1;
    	while(y){
    		if(y&1){
    			res = (1LL*res*x)%m;
    		}
    		x=(1LL*x*x)%m;
    		y>>=1;
    	}
    	return res;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%s", a);
    		int n=strlen(a), ans=0;
     
    		if(n&1){
    			ans=power(2, n);
    			for(int i=n;i>=0;i--){
    				if(i==n){
    					ans=(ans-1+m)%m;
    				}
    				else if(i==0){
    					ans=(ans-1+m)%m;
    				}
    				else if(i==1){
    					ans=(ans-n+m)%m;
    				}
    				else{	
    					if(i&1){
    						ans=(ans-nCr(n/2, (n-i)/2)+m)%m;
    						ans=(ans- ((1LL*2*nCr((n/2), (i+1)/2))%m) + m)%m;
    					}
    					else{
    						ans=(ans-nCr(n/2, (n-i)/2)+m)%m;
    					}
    				}
    			}
    		}
    		else{
    			ans=power(2, n);
    			for(int i=n;i>=0;i--){
    				if(i==n){
    					ans=(ans-1+m)%m;
    				}
    				else if(i==0){
    					ans=(ans-1+m)%m;
    				}
    				else{
    					if(i&1){
    						ans=(ans- ((1LL*2*nCr(n/2, (n-i)/2))%m) +m)%m;
    					}
    					else{
    						ans=(ans-nCr(n/2, (n-i)/2)+m)%m;
    					}
    				}
    			}
    		}
    		printf("%d\n", (ans+m)%m);
    	}
    	return 0;
    } 