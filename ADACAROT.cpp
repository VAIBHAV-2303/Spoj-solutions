    #pragma comment(linker, "/stack:200000000")
    #pragma GCC optimize("Ofast")
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
    #define _CRT_SECURE_NO_WARNINGS
    #include<bits/stdc++.h>
    using namespace std;
    const int m=1e9+7;
    int fact[200005];
     
    int power(int x, int y){
    	int res=1;
    	while(y>0){
    		if(y&1){
    			res=(1LL*res*x)%m;
    		}
    		x=(1LL*x*x)%m;
    		y=y>>1;
    	}
    	return res;
    }
     
    int main(){
    	ios_base :: sync_with_stdio(0);
        cin.tie(0);
    	fact[0]=1;
    	for(int i=1;i<=200000;i++){
    		fact[i]=1LL*i*fact[i-1]%m;
    	}
    	int n;
    	int ansp;
    	while(cin >> n){
    		ansp=0;
    		for(int i=1;i<=n-1;i++){
    			ansp=(ansp+(1LL * power(i, n-i-1) * (power(n-i, i-1)))%m)%m;
    		}
    		ansp=(1LL*ansp*fact[n])%m;
    		cout << ansp << endl;
    	}
    	return 0;
    } 
