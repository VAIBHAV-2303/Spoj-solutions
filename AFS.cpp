    #include<stdio.h>
    #include<math.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    vector<int> a;
    int spfa[10000];
    long long current;
    int spf(int x){
    	if(x<10000){
    		return spfa[x];
    	}
    	for(int i=0;primes[i]*primes[i]<=x;i++){
    		if((x%primes[i])==0){
    			return primes[i];
    		}
    	}
    	return x;
    }
    void generate(){
    	int isprime;
    	primes.push_back(2);
    	spfa[2]=2;
    	for(int i=3;i<10000;i++){
    		isprime=1;
    		for(int j=0;primes[j]*primes[j]<=i;j++){
    			if(i%primes[j]==0){
    				isprime=0;
    				spfa[i]=primes[j];
    				break;
    			}
    		}
    		if(isprime==1){
    			spfa[i]=i;
    			primes.push_back(i);
    		}
    	}
    }
    long long int num(int n){
    	int pui=n;
    	long long current=1, x, ong;
    	if(n==1){
    		return 0;
    	}
    	int isprime=1;
    	for(int j=0;primes[j]*primes[j]<=n;j++){
    		if(n%primes[j]==0){
    			isprime=0;
    			break;
    		}
    	}
    	if(isprime==0){
    		a.clear();
    		while(n!=1){
    			a.push_back(spf(n));
    			n=n/spf(n);
    		}
    		int i=0;
    		while(i<a.size()){
    			x=a[i];
    			ong=a[i];
    			while((i+1)<a.size() && a[i+1]==a[i]){
    				ong*=a[i];
    				x+=ong;
    				i++;
    			}
    			current*=(x+1);
    			i++;
    		}
    		return current-pui;
    	}
    	else{
    		return 1;
    	}
    }
    long long dp[1000006];
    long long fn(int n){
    	if(dp[n]==-1){
    		if(n<=1){
    			dp[n]=0;
    		}
    		else{
    			dp[n]=num(n)+fn(n-1);
    		}
    	}
    	return dp[n];
    }
    int main(){
    	for(int i=0;i<1000006;i++){
    		dp[i]=-1;
    	}
    	generate();
    	long long temp; 
    	for(int i=2;i<=900000;i++){
    		temp=fn(i);
    	}
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		printf("%lld\n", fn(n));
    	}
    } 
