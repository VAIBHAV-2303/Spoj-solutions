    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int check(double ch, long long x){
    	// printf("%lf\n", (log(ch)/log(3)));
    	ch = ch*(log(ch)/log(3));
    	// printf("%lf\n", ch);
    	if(ch<=x){
    		// printf("pui\n");
    		return 1;
    	}
    	return 0;
    }
    int main(){
    	int T, l, r, mid;
    	scanf("%d", &T);
    	while(T--){
    		long long t;
    		scanf("%lld", &t);
    		l=3, r=600000000;
    		while(r>=l){
    			// printf("%d %d\n", l, r);
    			if(l==r){
    				printf("%d\n", l);
    				break;
    			}
     
    			if(r-l==1){
    				if(check(r, t)==1){
    					printf("%d\n", r);
    				}
    				else{
    					printf("%d\n", l);
    				}
    				break;
    			}
     
    			mid=(l+r)/2;
    			if(check(mid, t)==1){
    				l=mid;
    			}
    			else{
    				r=mid-1;
    			}
    		}
    	}
    	return 0;
    } 
