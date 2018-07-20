    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int gcd(int x, int y){
    	if(y==0){
    		return x;
    	}
    	return gcd(y, x%y);
    }
    int main(){
    	int a, b, c, m, bada, chota;
    	long long lcmab, lcmabc, n, ans;
    	scanf("%d %d %d %d", &a, &b, &c, &m);
    	lcmab=(a*b)/gcd(a, b);
    	lcmabc=(a*b*c)/gcd(a*b, gcd(b*c, a*c));
    	// printf("%lld %lld\n", lcmabc, lcmab);
    	bada=(lcmabc/a) - (lcmabc/lcmab) + 1;
    	chota=(lcmab-1)/a;
    	while(m--){
    		scanf("%lld", &n);
    		ans=(n/bada)*(lcmabc);
    		n=n%bada;
    		// printf("%lld\n", ans);
    		ans+=((max(n-1, (long long)0))/chota)*lcmab;
    		n-=((max(n-1, (long long)0))/chota)*chota;
    		ans+=a*n;
    		printf("%lld\n", ans);
    	}
     
    	return 0;
    } 
