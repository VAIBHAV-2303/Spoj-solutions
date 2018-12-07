    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int M=1e9+7, factarr[1000005];
    int power(int x, int y){
    	int res=1;
    	while(y){
    		if(y&1){
    			res=(1LL*res*x)%M;
    		}
    		y>>=1;
    		x=(1LL*x*x)%M;
    	}
    	return res;
    }
    int main(){
     
    	factarr[0]=1;
    	for(int i=1;i<1000005;i++){
    		factarr[i]=(1LL*i*factarr[i-1])%M;
    	}
     
    	int n, m, ans;
    	long long k;
    	scanf("%d %d %lld", &n, &m, &k);
     
    	if(k>min(m, n)){
    		ans=0;
    	}
    	else{
    		ans=(1LL*factarr[n]*factarr[m])%M;
    		ans=(1LL*ans*power(factarr[k], M-2))%M;
    		ans=(1LL*ans*power(factarr[m-k], M-2))%M;
    		ans=(1LL*ans*power(factarr[n-k], M-2))%M;
    	}
    	printf("%d\n", ans);
    	return 0;
    } 