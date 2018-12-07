    #include<bits/stdc++.h>
    int m=1e9+7;
    int power(int x, long long y){
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
    	int ans, th=power(3, m-2);
    	long long n;
    	while(scanf("%lld", &n)!=EOF){
    		if(n&1){
    			ans=(1LL*(power(2, n)+1)*th)%m;
    			printf("%d\n", ans);
    		}
    		else{
    			ans=(1LL*(power(2, n)+2)*th)%m;
    			printf("%d\n", ans);
    			
    		}
    	}
    	return 0;
    } 