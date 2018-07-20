        #include<bits/stdc++.h>
        #include<stdio.h>
        using namespace std;
        int m=1e9+7;
        int factarr[1000001]={0};
        int power(int x, int y){
        	int res=1;
        	while(y){
        		if(y&1){
        			res=(1LL*res*x)%m;
        		}
        		y>>=1;
        		x=(1LL*x*x)%m;
        	}
        	return res%m;
        }
        int fact(int x){
        	if(factarr[x]==0){
        		if(x==0 || x==1){
        			factarr[x]=1;
        		}
        		else{
        			factarr[x]=(1LL*fact(x-1)*x)%m;
        		}
        	}
        	return factarr[x];
        }
        int nCr(int n, int r){
        	int ans=fact(n);
        	ans=(1LL*ans*power(fact(r), m-2))%m;
        	ans=(1LL*ans*power(fact(n-r), m-2))%m;
        	return ans;
        }
        int main(){
        	int n, a, b, d;
        	while(scanf("%d %d %d %d", &n, &a, &b, &d)!=EOF){
        		int nca = nCr(n, a);
        		int bcd = nCr(b, d);
        		bcd = power(bcd, a);
        		printf("%d\n", (1LL*nca*bcd)%m);
        	}
        }  
