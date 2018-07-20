    #include<stdio.h>
    using namespace std;
    long long int gcd(long long int a, long long int b){
    	if(b==0){
    		return a;
    	}
    	return gcd(b, a%b);
    }
    int main(){
    	int T;
    	long long x, y;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%lld %lld", &x, &y);
     
    		printf("%lld %lld\n", y/gcd(x, y), x/gcd(x, y));
     
    	}
    	return 0;
    } 
