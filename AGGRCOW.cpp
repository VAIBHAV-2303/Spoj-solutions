    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long pos[100005];
    int n, c;
    int check(long long d){
    	int temp=c, l=0;
    	temp--;
    	for(int i=0;i<n;i++){
    		if(pos[i]-pos[l]>=d){
    			temp--;
    			l=i;
    		}
     
    		if(temp==0){
    			return 1;
    		}
    	}
    	return 0;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%d %d", &n, &c);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &pos[i]);
    		}
    		sort(pos, pos+n);
     
    		long long l=0, r=10000000000000000, mid;
    		while(r>=l){
    			mid=l+((r-l)/2);
    			// printf("%lld %lld %lld\n", l, r, mid);
    			if(l==r){
    				printf("%lld\n", l);
    				// printf("pui\n");
    				break;
    			}
    			if(r-l==1){
    				if(check(r)==1){
    					printf("%lld\n", r);
    					// printf("pui\n");
    				}
    				else{
    					printf("%lld\n", l);
    				}
    				break;
    			}
    			
    			if(check(mid)==1){
    				l=mid;
    			}
    			else{
    				r=mid-1;
    			}
    		}
    	}
    	return 0;
    } 
