    #include<bits/stdc++.h>
    using namespace std;
    int m=1e9+7, factarr[305];
     
    int fact(int n){
    	if(factarr[n]==0){
    		if(n==0){
    			factarr[n]=1;
    		}
    		else{
    			factarr[n]=(1LL*fact(n-1)*n)%m;
    		}
    	}
    	return factarr[n];
    }
     
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
    	int n, w, t, r;
    	scanf("%d %d %d %d", &n, &w, &t, &r);
    	int ans=fact(n);
    	ans=(1LL*power(fact(w), m-2)*ans)%m;
    	ans=(1LL*power(fact(t), m-2)*ans)%m;
    	ans=(1LL*power(fact(r), m-2)*ans)%m;
    	printf("%d\n", ans);
    	return 0;
    } 