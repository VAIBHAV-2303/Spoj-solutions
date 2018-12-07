    #include<stdio.h>
    int main(){
    	int T, k, n, m, x;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%d %d %d", &k, &n, &m);
    		if(k==1){
    			if((n&1) && (m&1)){
    				printf("-\n");
    			}
    			else{
    				printf("+\n");
    			}
    			continue;
    		}
    		if(m>n){
    			x=m;
    			m=n;
    			n=x;
    		}
     
    		x=(n-m+1);
    		if((x&1)==0){
    			if(m<=(k+1)){
    				printf("+\n");
    			}
    			else{
    				m-=(k+1);
    				m--;
    				m=(m%(2*k+2));
    				if(m<k){
    					printf("-\n");
    				}
    				else{
    					printf("+\n");
    				}
    			}
    		}
    		else{
    			m--;
    			m=(m%(2*k+2));
    			if(m<k){
    				printf("-\n");
    			}
    			else{
    				printf("+\n");
    			}
    		}
    	}
    	return 0;
    } 