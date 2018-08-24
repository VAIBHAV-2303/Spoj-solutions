    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long int a[1003], n, k;
    bool check(long long mid){
    	long long sum=0;
    	for(int i=0;i<n;i++){
    		sum+=min(a[i], mid);
    	}
    	return (sum/mid)>=k;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		scanf("%lld %lld", &n, &k);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &a[i]);
    		}
    		printf("Case %d: ", t);
    		long long l=0, r=100000000000000, mid;
    		while(r>=l){
    			if(r==l){
    				printf("%lld\n", l);
    				break;
    			}
    			if(r-l==1){
    				if(check(r)){
    					printf("%lld\n", r);
    				}
    				else{
    					printf("%lld\n", l);
    				}
    				break;
    			}
    			mid=(l+r)/2;
    			if(check(mid)){
    				l=mid;
    			}
    			else{
    				r=mid-1;
    			}
    		}
    	}
    	return 0;
    } 
