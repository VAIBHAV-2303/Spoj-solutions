    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    int fn(int n){
    	if(n<=3){
    		return 1;
    	}
    	else{
    		if(n==4){
    			return 2;
    		}
    		else{
    			return fn(n-1)+fn(n-4);
    		}
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		primes.clear();
    		int n, m, isprime, count=1;
    		scanf("%d", &n);
    		m=fn(n);
    		primes.push_back(2);
     
    		for(int i=3;i<=m;i+=2){
    			isprime=1;
    			for(int j=0;primes[j]*primes[j]<=i;j++){
    				if(i%primes[j]==0){
    					isprime=0;
    					break;
    				}
    			}
    			if(isprime){
    				primes.push_back(i);
    				count++;
    			}
    		}
     
    		if(m<2){
    			printf("0\n");
    		}
    		else{
    			printf("%d\n", count);
    		}
    	}
    } 