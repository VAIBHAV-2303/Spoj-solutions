    #include<stdio.h>
    using namespace std;
    int m=11;
    int power(long long int x, long long y){
    	int res=1;
    	x=x%m;
    	while(y>0){
    		if(y&1){
    			res=(res*x)%m;
    		}
    		y=y/2;
    		x=(x*x)%m;
    	}
    	return res;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n;
    		scanf("%lld", &n);
    		printf("%lld\n", (11-(power(34, n)+((30%m)*(n%m))%m + 32%m)%m)%m);
     
    	}
    	return 0;
    } 
