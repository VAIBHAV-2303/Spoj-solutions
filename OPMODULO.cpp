    #include<stdio.h>
    using namespace std;
    int main(){
    	long long l, r;
    	scanf("%lld %lld", &l, &r);
     
    	unsigned long long ans=0;
    	long long x=1;
     
    	while(x<l){
    		x=2*x;
    	}
     
    	while(x<=r){
    		ans+=x;
    		x=2*x;
    	}
    	printf("%llu\n", ans);
     
    	return 0;
    } 
