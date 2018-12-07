    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    int main(){
    	int isprime;
    	primes.push_back(2);
    	for(int i=3;i<=10004;i+=2){
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
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int s, x;
    		scanf("%d %d", &s, &x);
    		isprime=1;
    		for(int j=0;primes[j]*primes[j]<=x+1;j++){
    			if((x+1)%primes[j]==0){
    				isprime=0;
    				break;
    			}
    		}
    		if(isprime){
    			printf("Friends\n");
    			continue;
    		}
     
    		isprime=1;
    		for(int j=0;primes[j]*primes[j]<=x;j++){
    			if(x%primes[j]==0){
    				isprime=0;
    				break;
    			}
    		}		
     
    		if(isprime){
    			printf("Friends\n");
    		}
    		else{
    			if(s==1){
    				printf("Second\n");
    			}
    			else{
    				printf("First\n");
    			}	
    		}
    	}
    	return 0;
    } 