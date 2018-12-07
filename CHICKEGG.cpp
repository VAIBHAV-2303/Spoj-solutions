    #include<bits/stdc++.h>
    using namespace std;
    long long int d[1003], k, n;
    int check(long long days){
    	long long int count=0;
    	for(long long int i=0;i<n;i++){
    		long long l=0, r=2000000000, mid;
    		while(r>=l){
    			if(r==l){
    				count+=r;
    				break;
    			}
    			else if(r-l==1){
    				if((r*d[i] + ((r*(r-1))/2)) <= days){
    					count+=r;
    				}
    				else{
    					count+=l;
    				}
    				break;
    			}
    			mid=(l+r)/2;
    			if((mid*d[i] + ((mid*(mid-1))/2)) <= days){
    				l=mid;
    			}
    			else{
    				r=mid;
    			}
    		}
    	}
     
    	if(count>=k){
    		return 1;
    	}
    	return 0;
     
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%lld %lld", &n, &k);
    		for(long long int i=0;i<n;i++){
    			scanf("%lld", &d[i]);
    		}
     
    		long long l=1, r=100000000000000000, mid;
     
    		while(r>=l){
    			if(r==l){
    				printf("%lld\n", l);
    				break;
    			}
    			if(r-l==1){
    				if(check(l)){
    					printf("%lld\n", l);
    				}
    				else{
    					printf("%lld\n", r);
    				}
    				break;
    			}
    			mid=(l+r)/2;
    			// printf("%lld %lld %lld\n", l, mid, r);
    			if(check(mid)){
    				r=mid;
    			}
    			else{
    				l=mid;
    			}
    		}
    	}
    	return 0;
    } 