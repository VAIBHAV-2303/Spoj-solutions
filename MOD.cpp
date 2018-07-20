    #include<cstdio>
    #include<cmath>
    #include<map>
    using namespace std;
    long long power(long long x, long long y, long long m){
        long long res=1;
        x=x%m;
        while(y){
            if(y&1){
                res=(res*x)%m;
            }
            y=y/2;
            x=(x*x)%m;
        }
        return res%m;
    }
    int gcd(int a, int b){
    	return b ? gcd(b, a % b) : a;
    }
    int baby_step_giant_step(int a, int b, int p){
    	a%=p, b%=p;
    	if(b==1) return 0;
    	int cnt = 0;
    	long long t = 1;
    	for(int g = gcd(a, p); g != 1; g = gcd(a, p))
    	{
    		if(b % g) return -1;
    		p /= g, b /= g, t = t * a / g % p;
    		++cnt;
    		if(b == t) return cnt;
    	}
     
    	map<int, int> hash;
    	int m = int(sqrt(1.0 * p) + 1);
    	long long base = b;
    	for(int i = 0; i != m; ++i)
    	{
    		hash[base] = i;
    		base = base * a % p;
    	}
     
    	base = power(a, m, p);
    	long long now = t;
    	for(int i = 1; i <= m + 1; ++i)
    	{
    		now = now * base % p;
    		if(hash.count(now))
    			return i * m - hash[now] + cnt;
    	}
     
    	return -1;
    }
     
    int main()
    {
    	int a, b, p;
    	while(std::scanf("%d %d %d", &a, &p, &b), p)
    	{
    		int ans = baby_step_giant_step(a, b, p);
    		if(ans == -1) puts("No Solution");
    		else printf("%d\n", ans);
    	}
    	return 0;
    } 
