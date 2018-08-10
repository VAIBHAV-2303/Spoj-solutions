    #include<stdio.h>
    int main(){
    	long long n, p;
    	scanf("%lld %lld", &n, &p);
    	if(n==1){
    		printf("%lld\n", 2%p);
    	}
    	else if(n==2){
    		printf("%lld\n", 3%p);
    	}
    	else if(n==3){
    		printf("%lld\n", 7%p);
    	}
    	else{
    		printf("Impossible\n");
    	}
    } 
