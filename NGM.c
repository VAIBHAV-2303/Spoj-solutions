    #include<stdio.h>
    int main(){
    	long long n;
    	scanf("%lld", &n);
    	if(n%10==0){
    		printf("2\n");
    	}
    	else{
    		printf("1 %lld\n", n%10);
    	}
    	return 0;
    } 
