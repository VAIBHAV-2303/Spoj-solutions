    #include<stdio.h>
    #include<math.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long k, pui;
    		scanf("%lld", &k);
    		k--;
    		pui=(k/4)*1000;
    		if(k%4==0){
    			printf("%lld\n", pui+192);
    		}
    		else if(k%4==1){
    			printf("%lld\n", pui+442);
    		}
    		else if(k%4==2){
    			printf("%lld\n", pui+692);
    		}
    		else{
    			printf("%lld\n", pui+942);
    		}
    	}
    	return 0;
    } 
