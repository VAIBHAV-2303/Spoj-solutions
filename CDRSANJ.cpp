    #include<stdio.h>
    #include<math.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    void generate(){
    	primes.push_back(2);
    	int isprime;
    	for(int i=3;i<320;i+=2){
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
    long long fn(int x){
    	if(x<=2){
    		return x;
    	}
    	int isprime=1;
    	for(int j=0;primes[j]*primes[j]<=x;j++){
    		if(x%primes[j]==0){
    			isprime=0;
    			break;
    		}
    	}
     
    	if(isprime){
    		// printf("pui\n");
    		return 0;
    	}
    	int k=(int)sqrt(x);
    	while(x%k){
    		k--;
    	}
    	return fn(k)+fn(x/k);
    }
    int main(){
    	generate();
    	int x;
    	scanf("%d", &x);
    	printf("%lld\n", fn(x));
    	return 0;
    } 
