    #include<stdio.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n, x;
    		int k, count=0;
    		scanf("%lld %d", &n, &k);
    		if(k==0){
    			printf("-1\n");
    			continue;
    		}
     
    		n--;
    		x=n;
    		while(x!=0){
    			count+=(x%2);
    			x=x/2;
    		}
     
    		x=2;
    		// printf("%d %d\n", n, count);
    		while(count>k){
    			if((n & x)==x){
    				n=n-x;
    				count--;
    			}
    			x=x*2;
    		}
     
    		printf("%lld\n", n);
     
    	}
    	return 0;
    } 
