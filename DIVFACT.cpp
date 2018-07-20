    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    vector<int> powers;
    long long M=1000000007;
    long long fn(int prime, int n){
    	long long partial=0, x=prime;
    	while((n/x)!=0){
    		partial+=n/x;
    		x=x*prime;
    	}
    	return partial;
    }
    int isprime(int n){
    	for(int i=2;i*i<=n;i++){
    		if(n%i==0){
    			return 0;
    		}
    	}
    	return 1;
    }
    int main(){
    	primes.clear();
    	for(int i=2;i<60000;i++){
    		if(isprime(i)==1){
    			primes.push_back(i);
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		powers.clear();
    		int n;
    		scanf("%d", &n);
    		long long ans=1;
    		for(int i=0;i<primes.size();i++){
    			powers.push_back(fn(primes[i], n));
    		}
     
    		for(int i=0;i<powers.size();i++){
    			ans=((ans%M)*((powers[i]+1)%M))%M;
    		}
    		printf("%lld\n", ans);
     
    	}
    	return 0;
    } 
