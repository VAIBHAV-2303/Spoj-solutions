    #include<stdio.h>
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n, k;
    		scanf("%lld %lld", &n, &k);
    		if(k==0){
    			printf("Airborne wins.\n");
    		}
    		else{
    			printf("Pagfloyd wins.\n");
    		}
    	}
    	return 0;
    } 
