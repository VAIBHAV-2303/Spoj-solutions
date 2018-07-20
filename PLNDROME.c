    #include<stdio.h>
    int main(){
    	int T;
    	char a[100005], x;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int n, q, imp=0, p;
    		scanf("%d", &n);
    		scanf("%s", a);
     
    		for(int i=0;i<n/2;i++){
    			if(a[i]!=a[n-1-i]){
    				imp++;
    			}
    		}
     
    		scanf("%d", &q);
    		printf("Case %d:\n", t);
    		while(q--){
    			scanf("%d %c", &p, &x);
    			p--;
    			if(a[p]==a[n-p-1]){
    				a[p]=x;
    				if(a[p]==a[n-p-1]){
    					if(imp==0){
    						printf("YES\n");
    					}
    					else{
    						printf("NO\n");
    					}
    				}
    				else{
    					imp++;
    					printf("NO\n");
    				}
    			}
    			else{
    				a[p]=x;
    				if(a[p]==a[n-p-1]){
    					imp--;
    					if(imp==0){
    						printf("YES\n");
    					}
    					else{
    						printf("NO\n");
    					}
    				}
    				else{
    					printf("NO\n");
    				}	
    			}
    		}
     
    	}
    	return 0;
    } 
