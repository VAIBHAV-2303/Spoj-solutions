    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long gcd(long x, long y){
    	if(y==0){
    		return x;
    	}
    	return gcd(y, x%y);
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long int u, v, rel, small;
    		scanf("%lld %lld", &u, &v);
    		rel=abs(u-v);
    		small=min(abs(u), abs(v));
    		printf("%lld\n", rel/gcd(rel, small));	
    	}
    	return 0;
    } 
