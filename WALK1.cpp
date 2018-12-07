    #include<bits/stdc++.h>
    using namespace std;
    int m=500000003, factarr[1000006], ifactarr[1000006];
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
    	return (1LL*factarr[n]* ((1LL*ifactarr[n-r]*ifactarr[r])%m) )%m;
    }
    int fn(int n, int x){
    	if(n<x){
    		return 0;
    	}
     
    	if(((n-x)%2) == 1){
    		return 0;
    	}
     
    	return nCr(n, ((n-x)/2));
     
    }
    int main(){
    	factarr[0]=1;
    	for(int i=1;i<1000006;i++){
    		factarr[i]=(1LL*factarr[i-1]*i)%m;
    	}
    	ifactarr[1000005] = power(factarr[1000005], m-2);
    	for(int i=1000005; i>0; --i ){
    		ifactarr[i-1]=(1LL*i*ifactarr[i])%m;
    	}
     
    	int n, x, y, ans=0;
    	scanf("%d %d %d", &n, &x, &y);
     
    	x=abs(x);
    	y=abs(y);
     
    	for(int i=0;i<=n;i++){
    		ans=(ans+ (1LL*nCr(n, i) * (1LL*fn(i, x)*fn(n-i, y)%m) %m) )%m;
    	}
     
    	printf("%d\n", ans);
     
    	return 0;
    } 