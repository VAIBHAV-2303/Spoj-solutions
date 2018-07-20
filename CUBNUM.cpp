    #include<stdio.h>
    #include<math.h>
    using namespace std;
    long long int dp[100005];
    long long fn(int n){
    	if(dp[n]==-1){
    		if(n==0){
    			dp[n]=0;
    		}
    		else{
    			long long currmin=100000000000;
    			for(int i=1;i*i*i<=n;i++){
    				if(1+fn(n-(i*i*i))<currmin){
    					currmin=1+fn(n-(i*i*i));
    				}
    			}
    			dp[n]=currmin;
    		}
    	}
    	return dp[n];
    }
    int main(){
     
    	for(int i=0;i<100005;i++){
    		dp[i]=-1;
    	}
    	int t=0, n;
    	while(scanf("%d", &n)!=EOF){
    		t++;
    		printf("Case #%d: %lld\n", t, fn(n));
    	}
    	return 0;
    } 
