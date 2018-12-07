    #include<stdio.h>
    int m = 1e9 + 7;
    int power(int x, int y){
    	int res=1;
    	while(y){
    		if(y&1){
    			res=(1LL*res*x)%m;
    		}
    		y>>=1;
    		x=(1LL*x*x)%m;
    	}
    	return res;
    }
    int main(){
    	int xi[55], yi[55], factarr[505], ifactarr[505];
    	factarr[0]=1;
    	for(int i=1;i<505;i++){
    		factarr[i]=(1LL*i*factarr[i-1])%m;
    	}
    	ifactarr[504]=power(factarr[504], m-2);
    	for(int i=503;i>=0;i--){
    		ifactarr[i]=(1LL*(i+1)*ifactarr[i+1])%m;
    	}
    	while(1){
    		int n, total=0;
    		scanf("%d", &n);
    		if(n==0){
    			return 0;
    		}
     
    		for(int i=0;i<n;i++){
    			scanf("%d", &xi[i]);
    		}
    		for(int i=0;i<n;i++){
    			scanf("%d", &yi[i]);
    			total+=yi[i]-xi[i];
    		}
     
    		int ans=factarr[total];
    		// printf("%d\n", ans);
    		for(int i=0;i<n;i++){
    			ans=(1LL*ans*ifactarr[yi[i]-xi[i]])%m;
    			// printf("%d\n", power(factarr[yi[i]-xi[i]], m-2));
    			// printf("%d\n", ans);
    		}
    		printf("%d\n", ans);
     
    	}
    } 