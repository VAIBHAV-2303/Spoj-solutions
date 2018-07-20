    #include<stdio.h>
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		unsigned long long n;
    		scanf("%llu", &n);
    		if(n%2==0 || n==1){
    			printf("HuseyNO\n");
    		}
    		else{
    			int count=0;
    			while(n%2==1){
    				n=(n+1)/2;
    				count++;
    			}
    			if(count%2){
    				printf("ZiYES\n");
    			}
    			else{
    				printf("HuseyNO\n");
    			}
    		}
    	}
    	return 0;
    } 
