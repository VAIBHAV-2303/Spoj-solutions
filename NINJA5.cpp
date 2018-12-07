    #include<stdio.h>
    int a[2000006];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, k, x;
    		scanf("%d %d", &n, &k);
     
    		for(int i=1;i<=n+1;i++){
    			a[i]=0;
    		}
     
    		for(int i=0;i<k;i++){
    			scanf("%d", &x);
    			a[x]=1;
    		}
    		int count=0;
    		for(int i=1;i<=n;i++){
    			if(a[i]==0){
    				if(a[i-1]==0 && a[i+1]==0){
    					a[i]=1;
    					count++;
    				}
    			}	
    			else{
    				count++;
    			}
    		}
    		printf("%d\n", count);
    	}
    	return 0;
    } 