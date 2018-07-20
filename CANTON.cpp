    #include<stdio.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long int n, t;
    		scanf("%lld", &n);
    		t=n;
    		long long int x=0;
    		while((x*(x+1))/2<n){
    			x++;
    		}
    		x--;
    		t-=(x*(x+1))/2;
    		x++;
    		if(x%2==0){
    			printf("TERM %lld IS %lld/%lld\n", n, 1+t-1, x-t+1);
    		}
    		else{
    			printf("TERM %lld IS %lld/%lld\n", n, x-t+1, 1+t-1);
    		}
     
    	}
    	return 0;
    } 
