    #include<stdio.h>
    #include<bits/stdc++.h>
    #include<math.h>
    using namespace std;
    vector<int> primes;
    long long m=1e9+7;
    long long power(long long x, long long y){
    	long long res=1;
    	x=x%m;
    	while(y>0){
    		if(y&1){
    			res=((res%m)*(x%m))%m;
    		}
    		y=y/2;
    		x=((x%m)*(x%m))%m;
    	}
    	return res%m;
    }
    void generate(){
    	primes.push_back(2);
    	int isprime;
    	for(int i=3;i<100006;i+=2){
    		isprime=1;
    		for(int j=0;primes[j]*primes[j]<=i;j++){
    			if(i%primes[j]==0){
    				isprime=0;
    				break;
    			}
    		}
    		if(isprime){
    			primes.push_back(i);
    		}
    	}
    }
    int primehai(long long int x){
    	if(x==1){
    		return 0;
    	}
    	int isprime=1;
    	for(int j=0;primes[j]*primes[j]<=x;j++){
    		if(x%primes[j]==0){
    			isprime=0;
    			break;
    		}
    	}
    	return isprime;
    }
    int main(){
    	generate();
    	long long int n, k, a;
    	scanf("%lld %lld", &n, &k);
    	long long ans=0;
    	for(int i=0;i<n;i++){
    		scanf("%lld",  &a);
    		if(a==1){
    			a=((a%m)+(2*k)%m)%m;
    			int curmax=-1;
    			for(int j=1;j*j<=a;j++){
    				if(a%j==0){
    					if(primehai(a/j)){
    						curmax=a/j;
    						break;
    					}
    					if(primehai(j)){
    						curmax=j;
    					}
    				}
    			}
    			ans+=curmax;
    		}
    		else{
    			a=((a%m)+(k%m)+((power(2, a-2)*k)%m))%m;
    			int curmax=-1;
    			for(int j=1;j*j<=a;j++){
    				if(a%j==0){
    					if(primehai(a/j)){
    						curmax=a/j;
    						break;
    					}
    					if(primehai(j)){
    						curmax=j;
    					}	
    				}
    			}	
    			ans+=curmax;
    		}
    	}
    	printf("The President needs to pay %lld dollar(s)\n", ans);
    	return 0;
    } 
