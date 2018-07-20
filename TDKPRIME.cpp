    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<bool> arr (86028122, true);
    vector<long long> primes;
    int main(){
    	arr[0]=false;
    	arr[1]=false;
    	for(long long i=2;i*i<86028122;i++){
    		if(arr[i] == true){
    			for(long long j=i;j*i<86028122;j++){
    				arr[j*i]=false;
    			}	
    		}
    	}
    	primes.push_back(2);
    	for(long long int i=3;i<86028122;i+=2){
    		if(arr[i]){
    			primes.push_back(i);
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		printf("%lld\n", primes[n-1]);
    	}
    	return 0;
    } 
