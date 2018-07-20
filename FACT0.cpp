    #include<stdio.h>
    using namespace std;
    int a[31622778];
    long long x;
    void fn(long long n){
    	for(long long i=2;i*i<=n;i++){
    		if(n%i==0){
    			a[i]++;
    			return fn(n/i);
    		}
    	}
    	if(n<=31622777){
    		a[n]++;
    	}
    	else{
    		x=n;
    	}
    }
    int main(){
    	while(1){
    		x=1;
    		long long n;
    		scanf("%lld", &n);
    		if(n==0){
    			break;
    		}
     
    		for(long long i=1;i<31622778;i++){
    			a[i]=0;
    		}
     
    		fn(n);
     
    		for(long long i=2;i<31622778;i++){
    			if(a[i]!=0){
    				printf("%lld^%d ", i, a[i]);
    			}
    		}
    		if(x!=1){
    			printf("%lld^1", x);
    		}
    		printf("\n");
     
    	}
    	return 0;
    } 
