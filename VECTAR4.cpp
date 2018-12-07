    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n, l, r, mid;
    		scanf("%lld", &n);
     
    		l=1, r=1000000000, mid;
     
    		while(r>=l){
    			if(r==l){
    				mid=l;
    				break;
    			}
    			if(r-l==1){
    				if(l*(l+1)>=n){
    					mid=l;
    				}
    				else{
    					mid=r;
    				}
    				break;
    			}
    			mid=(l+r)/2;
     
    			if(mid*(mid+1)>=n){
    				r=mid;
    			}
    			else{
    				l=mid;
    			}
    		}
     
    		if((mid*(mid+1))-n>=mid){
    			printf("%lld\n", 2*mid-1);
    		}
    		else{
    			printf("%lld\n", 2*mid);
    		}
    	}
    	return 0;
    } 