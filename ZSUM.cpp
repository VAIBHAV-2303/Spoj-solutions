    #include<stdio.h>
    using namespace std;
    long long m=1e7+7;
    long long power(long long x, long long y){
    	long long res=1;
    	while(y>0){
    		if(y&1){
    			res=((res%m)*(x%m))%m;
    		}
    		y>>=1;
    		x=((x%m)*(x%m))%m;
    	}
    	return res;
    }
    int main(){
    	long long n, k, ans;
    	while(1){
    		scanf("%lld %lld", &n, &k);
    		if(n==0 && k==0){
    			break;
    		}
    		ans=(power(n-1, k)+power(n-1, n-1))%m;
    		ans=(2*ans)%m;
    		ans=(ans+power(n, k))%m;
    		ans=(ans+power(n, n))%m;
    		printf("%lld\n", ans);
     
    	}
    	return 0;
    } 
