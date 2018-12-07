    #include<bits/stdc++.h>
    using namespace std;
    long long m=1e9+7;
    long long int power(long long int x, long long y){
    	long long int res=1;
    	while(y){
    		if(y&1){
    			res=(res*x)%m;
    		}
    		y>>=1;
    		x=(x*x)%m;
    	}
    	return res;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	long long n, p, x, z;
    	while(T--){
    		
    		scanf("%lld %lld", &n, &p);
     
    		if(p==1){
    			printf("%lld 1\n", n);
    			continue;
    		}
     
    		x=power(p, n-1);
     
    		z=(x*p)%m;
    		z=(z-1+m)%m;
     
    		z=(z*power(p-1, m-2))%m;
     
    		printf("%lld %lld\n", z, x);
    	}
    	return 0;
    } 