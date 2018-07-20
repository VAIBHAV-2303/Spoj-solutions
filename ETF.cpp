    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    void generate(){
    	primes.push_back(2);
    	int isprime;
    	for(int i=3;i<10004;i+=2){
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
    int isprime(int x){
    	int pui=1;
    	for(int j=0;primes[j]*primes[j]<=x;j++){
    		if(x%primes[j]==0){
    			pui=0;
    			break;
    		}
    	}
    	return pui;
    }
    int main(){
    	generate();
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
     
    		if(n==1){
    			printf("1\n");
    			continue;	
    		}
     
    		long long int res=n, flag=0;
    		for(int i=2;i*i<=n;i++){
    			if(n%i==0){
    				if(i*i==n){
    					if(isprime(i)){
    						res=(res-(res/i));	
    						flag=1;
    					}
    				}
    				else{
    					if(isprime(i)){
    						flag=1;
    						res=(res-(res/i));
    					}
    					if(isprime(n/i)==1){
    						flag=1;
    						res=(res-(res/(n/i)));
    					}	
    				}
    			}
    		}
    		if(flag==0){
    			printf("%d\n", n-1);
    			continue;
    		}
    		printf("%lld\n", res);
     
    	}
    	return 0;
    }	 
