    #include<bits/stdc++.h>
    using namespace std;
    int m=1e9+7;
    int power(int x, int y){
    	int res=1;
    	while(y){
    		if(y&1){
    			res=(1LL*res*x)%m;
    		}
    		x=(1LL*x*x)%m;
    		y>>=1;
    	}
    	return res%m;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int n;
    		scanf("%d", &n);
    		int ans=n, pui;
    		ans=(1LL*ans*(n-1))%m;
    		ans=(1LL*ans*power(2, m-2))%m;
    		ans=(1+ans)%m;
     
    		pui=n;
    		pui=(1LL*pui*(n-1))%m;
    		pui=(1LL*pui*(n-2))%m;
    		pui=(1LL*pui*(n-3))%m;
    		pui=(1LL*pui*power(24, m-2))%m;
     
    		printf("Case %d: %d\n", t, (ans+pui)%m );
     
    	}
    	return 0;
    } 