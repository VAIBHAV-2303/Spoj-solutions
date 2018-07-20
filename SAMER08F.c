    #include<stdio.h>
    int main(){
    	while(1){
    		int n;
    		long long ans=0;
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
     
    		for(int i=1;i<=n;i++){
    			ans+=(i*i);
    		}
     
    		printf("%lld\n", ans);
     
    	}
    	return 0;
    } 
