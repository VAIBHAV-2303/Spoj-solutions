    #include<bits/stdc++.h>
    using namespace std;
    long long m=1e9+7;
    long long power(long long x, long long y){
    	long long int res=1;
    	x=x%m;
    	while(y){
    		if(y&1){
    			res= (res*x)%m;
    		}
    		y>>=1;
    		x=(x*x)%m;
    	}
    	return res;
    }
    int main(){
    	long long n;
    	scanf("%lld", &n);
    	if(n<=4){
    		printf("%lld\n", n);
    	}
    	else{
    		if(n%3==0){
    			printf("%lld\n", power(3, (n/3)));
    		}
    		else if(n%3==1){
    			printf("%lld\n", (1LL*power(3, (n/3)-1)*4)%m);
    		}
    		else{
    			printf("%lld\n", (1LL*power(3, (n/3)-1)*6)%m);
    		}
    	}
    	return 0;
    } 
