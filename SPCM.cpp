    #include<bits/stdc++.h>
    using namespace std;
    vector<bool> arr (1000006, true);
    vector<int> primes;
    int Isprime(long long n){
    	int isprime=1;
    	for(int i=0;(1LL*primes[i]*primes[i])<=n;i++){
    		if((n%primes[i])==0){
    			isprime=0;
    			break;
    		}
    	}
     
    	if(isprime){
    		return 1;
    	}
    	return 0;
    }
    int fn(long long n){
     
    	if(Isprime(n)){
    		return 1;
    	}
     
    	int partial=0;
    	long long pui=0;
    	for(long long int i=2;i*i<=n;i++){
    		if(n%i==0){
    			if(i*i==n){
    				if(Isprime(i)){
    					pui+=i;
    					partial++;
    				}
    			}
    			else{
    				// printf("%lld\n", i);
    				if(Isprime(i)){
    					pui+=i;
    					partial++;
    				}
    				if(Isprime(n/i)){
    					pui+=(n/i);
    					partial++;
    				}
    			}
    		}
    	}
    	return partial+fn(pui);
    }
    int main(){
     
    	arr[0]=false;
    	arr[1]=false;
    	for(int i=2;i*i<1000006;i++){
    		if(arr[i] == true){
    			for(int j=i;j*i<1000006;j++){
    				arr[j*i]=false;
    			}	
    		}
    	}
    	primes.push_back(2);
    	for(int i=3;i<1000006;i+=2){
    		if(arr[i]){
    			primes.push_back(i);
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n;
    		scanf("%lld", &n);
    		printf("%d\n", fn(n));
    	}
    	return 0;
    } 