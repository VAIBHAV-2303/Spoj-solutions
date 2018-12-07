    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n, x;
    		scanf("%lld", &n);
    		if(n<0){
    			x=1;
    			while(n/x!=0){
    				x*=10;
    			}
    			x/=10;
    			printf("%lld\n", 2*abs(n)+x);
    		}
    		else if(n==0){
    			printf("1\n");
    		}
    		else{
    			x=1;
    			while(n/x!=0){
    				x*=10;
    			}
    			x/=10;
    			printf("%lld\n", x);
    		}
    	}
    	return 0;
    } 