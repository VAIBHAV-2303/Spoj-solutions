    #include<stdio.h>
    int m=5000011, factarr[200005], ifactarr[200005];
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
    int nCr(int n, int r){
    	int res=factarr[n];
    	res=(1LL*res*ifactarr[r])%m;
    	return (1LL*res*ifactarr[n-r])%m;
    }
    int main(){
     
    	factarr[0]=1;
    	for(int i=1;i<200005;i++){
    		factarr[i]=(1LL*i*factarr[i-1])%m;
    	}
    	ifactarr[200004]=power(factarr[200004], m-2);
    	for(int i=200003;i>=0;i--){
    		ifactarr[i]=(1LL*ifactarr[i+1]*(i+1))%m;
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, k, ans=1, upar, niche;
    		scanf("%d %d", &n, &k);
     
    		for(int i=1;(i+(i-1)*(k))<=n;i++){
    			// printf("%d\n", ans);
    			upar=n-i-((i-1)*k);
    			niche=(i+1);
    			ans=(ans+ nCr(upar+niche-1, niche-1) )%m;
    		}
    		printf("%d\n", ans);
    	}
    	return 0;
    } 