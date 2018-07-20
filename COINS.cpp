    #include<stdio.h>
    using namespace std;
    long long fn(long long n){
    	if(n/2 + n/3 + n/4 > n){
    		return fn(n/2) + fn(n/3) + fn(n/4);
    	}
    	return n;
    }
    int main(){
    	long long n;
    	while(scanf("%lld", &n)!=EOF){
    		printf("%lld\n", fn(n));
    	}
    	return 0;
    } 
