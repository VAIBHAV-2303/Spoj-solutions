    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long unsigned l, r;
    		scanf("%llu %llu", &l, &r);
     
    		long long unsigned d=(r-l);
     
    		if(d==0){
    			printf("1\n");
    			continue;
    		}
     
    		long long unsigned num=0, x=2;
    		while(num+x<d){
    			num+=x;
    			x<<=1;
    		}
    		x>>=1;
    		if(d-num<=(x+1)){
    			printf("%llu\n", d-num-1);
    		}
    		else{
    			printf("%llu\n", x-(d-num-x)+1);
    		}
    	}
    	return 0;
    } 