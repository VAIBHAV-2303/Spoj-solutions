    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){ 
        	long long term, m, mid, n, l, r;
        	scanf("%lld %lld", &n, &m);    
        	l=2, r=n;
         
        	while(r>=l){
                if(r==l){
                    printf("%lld\n", r);
                    break;
                }
                if(r-l==1){
                    mid=l;
                    term=(n*n - (n%mid)*ceil(((double)n)/((double)mid))*ceil(((double)n)/((double)mid)) - (mid-(n%mid))*(n/mid)*(n/mid))/2;
                    if(term>=m){
                        printf("%lld\n", l);
                        break;
                    }
                    printf("%lld\n", r);
                    break;
                }
         
                mid=(r+l)/2;
                // printf("%lld %lld %lld\n", l, mid, r);
        		term=(n*n - (n%mid)*ceil(((double)n)/((double)mid))*ceil(((double)n)/((double)mid)) - (mid-(n%mid))*(n/mid)*(n/mid))/2;
                // printf("%lld\n", term);
        		
        		if(term>=m){
        			r=mid;
        		}
        		else{
        			l=mid+1;
        		}
            } 
        }
    	return 0;
    }  
