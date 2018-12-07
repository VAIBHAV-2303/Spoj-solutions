    #include<stdio.h>
    int main(){
    	int T;
    	scanf("%d", &T);
    	long long m=1e9+7;
    	while(T--){
    		long long n;
    		scanf("%lld", &n);
     
    		printf("%lld\n", ((2*((n+1)))/3)%m);
     
    	}
    	return 0;
    } 