    #include<bits/stdc++.h>
    #include<stdio.h>
    #include<math.h>
    using namespace std;
    int check(int n, int a){
    	n=(double)n;
    	double temp=n*log(n)-n+(0.5*log(2*M_PI*n));
    	if(temp>=n*log(a)){
    		return 1;
    	}
    	return 0;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int a;
    		scanf("%d", &a);
    		int r=3000000, l=3, mid;
    		while(r>=l){
    			mid=(l+r)/2;
    			if(r==l){
    				printf("%d\n", l);
    				break;
    			}
     
    			if(check(mid, a)==1){
    				r=mid;
    			}
    			else{
    				l=mid+1;
    			}
    		}
    	}
    	return 0;
    } 
