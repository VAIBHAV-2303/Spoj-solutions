    #include<bits/stdc++.h>
    using namespace std;
    int factarr[10004], m=1e9+7, a[10004];
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
    	int ans=factarr[n];
    	ans=(1LL*ans*power(factarr[r], m-2))%m;
    	ans=(1LL*ans*power(factarr[n-r], m-2))%m;
    	return ans;
    }
    int main(){
     
    	factarr[0]=1;
    	for(int i=1;i<10004;i++){
    		factarr[i]=(1LL*factarr[i-1]*i)%m;
    	}
     
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int n, k;
    		scanf("%d %d", &n, &k);
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		sort(a, a+n, greater<int>());
    		int ans=0;
    		for(int i=0;i<=n-k;i++){
    			ans=(ans + ((1LL*a[i]*nCr(n-i-1, k-1))%m) )%m;
    		}
    		printf("Case #%d: %d\n", t, ans);
    	}
    	return 0;
    } 