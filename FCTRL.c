    #include<stdio.h>
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int ans=0;
    		long long n;
    		scanf("%lld", &n);
    		long long x=5;
    		while(n/x!=0){
    			ans+=(n/x);
    			x=x*5;
    		}
    		printf("%d\n", ans);
    	}
    	return 0;
    } 
