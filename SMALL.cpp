    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<bool> arr (10008, true);
    vector<int> primes;
    int main(){
     
    	arr[0]=false;
    	arr[1]=false;
    	for(int i=2;i*i<10008;i++){
    		if(arr[i] == true){
    			for(int j=i;j*i<10008;j++){
    				arr[j*i]=false;
    			}	
    		}
    	}
    	primes.push_back(2);
    	for(int i=3;i<10008;i+=2){
    		if(arr[i]){
    			primes.push_back(i);
    		}
    	}
     
    	int T, m=1e9+7;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		
    		int lcm=1, x;
     
    		for(int i=0;primes[i]<=n;i++){
    			x=primes[i];
    			while(x*primes[i]<=n){
    				x=x*primes[i];
    			}
    			lcm=(1LL*lcm*x)%m;
    		}
    		printf("%d\n", lcm);
    	}
    	return 0;
    } 