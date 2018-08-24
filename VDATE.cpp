    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long x, y, ans=0;
    		scanf("%lld %lld", &x, &y);
    		if(x==y){
    			printf("-1\n");
    			continue;
    		}
    		if(y>x){
    			printf("0\n");
    			continue;
    		}
     
    		x-=y;
     
    		for(long long int i=1;i*i<=x;i++){
    			if(x%i == 0){
    				if(i*i==x){
    					if(i>y){
    						ans++;
    					}
    				}
    				else{
    					if((x/i)>y){
    						ans++;
    					}
    					if(i>y){
    						ans++;
    					}
    				}
    			}
    		}
    		printf("%lld\n", ans);
    	}
    	return 0;
    } 
