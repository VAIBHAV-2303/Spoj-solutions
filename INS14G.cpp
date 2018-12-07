    #include<bits/stdc++.h>
    using namespace std;
    int m=1e9+7, factarr[1000006], ifactarr[1000006];
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
    	factarr[0]=1;
    	for(int i=1;i<1000006;i++){
    		factarr[i]=(1LL*factarr[i-1]*i)%m;
    	}
    	ifactarr[1000005]=power(factarr[1000005], m-2);
    	for(int i=1000004;i>=0;i--){
    		ifactarr[i]=(1LL*(i+1)*ifactarr[i+1])%m;
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		n--;
    		int ans=factarr[n];
    		ans=(1LL*ifactarr[n/2]*ans)%m;
    		ans=(1LL*ifactarr[n-(n/2)]*ans)%m;
    		printf("%d\n", ans);
    	}
    	return 0;
    }
     