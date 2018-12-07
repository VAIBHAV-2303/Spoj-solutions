    #include<bits/stdc++.h>
    using namespace std;
    vector<bool> arr (100005, true);
    vector<long long> prsq;
    int main(){
    	arr[0]=false;
    	arr[1]=false;
    	for(long long int i=2;i*i<=100005;i++){
    		if(arr[i]==true){
    			for(long long int j=i;j*i<=100005;j++){
    				arr[j*i]=false;
    			}	
    		}
    	}
    	prsq.push_back(4);
    	for(long long i=3;i<100005;i+=2){
    		if(arr[i]){
    			prsq.push_back(i*i);
    		}
    	}
     
    	int T, first, second;
    	scanf("%d", &T);
    	long long n, k;
    	while(T--){
    		scanf("%lld %lld", &n, &k);
     
    		first=(lower_bound (prsq.begin(), prsq.end(), n)-prsq.begin());
    		if(prsq[first]==n){
    			printf("%d ", first+1);
    			second=lower_bound (prsq.begin(), prsq.end(), k)-prsq.begin();
    			if(prsq[second]==k){
    				printf("%d\n", max(first-second, 0));	
    			}
    			else{
    				printf("%d\n", max(first-second+1, 0));
    			}
    		}
    		else{
    			printf("%d ", first);
    			second=lower_bound (prsq.begin(), prsq.end(), k)-prsq.begin();
    			if(prsq[second]==k){
    				printf("%d\n", max(first-second-1, 0));	
    			}
    			else{
    				printf("%d\n", max(first-second, 0));
    			}
    		}
    	}
    	return 0;
    } 