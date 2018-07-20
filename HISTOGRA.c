    #include<stdio.h>
    long long a[100005];
    typedef struct new{
    	long long data;
    	int ind;
    }new;
    new st[100005];
    int l[100005];
    int r[100005];
    int main(){
    	int n, i, j;
    	scanf("%d", &n);
    	while(n!=0){
    		for(i=1;i<=n;i++){
    			scanf("%lld", &a[i]);
    		}
    		a[0]=-1;
    		a[n+1]=-1;
    		j=0;
    		st[0].data=a[0];
    		st[0].ind=0;
    		for(i=1;i<=n+1;i++){
    			if(a[i]>=st[j].data){
    				j++;
    				st[j].data=a[i];
    				st[j].ind=i;
    			}
    			else{
    				while(st[j].data>a[i]&&j>=0){
    					r[st[j].ind]=i-st[j].ind-1;
    					j--;
    				}
    				j++;
    				st[j].data=a[i];
    				st[j].ind=i;
    			}
    		}
    		//for(i=1;i<=n;i++){
    		//	printf("%d ", r[i]);
    		//}
    		//printf("\n");
     
    		j=0;
    		st[0].data=a[n+1];
    		st[0].ind=n+1;
    		for(i=n;i>=0;i--){
    			if(a[i]>=st[j].data){
    				j++;
    				st[j].data=a[i];
    				st[j].ind=i;
    			}
    			else{
    				while(st[j].data>a[i]&&j>=0){
    					l[st[j].ind]=st[j].ind-i-1;
    					j--;
    				}
    				j++;
    				st[j].data=a[i];
    				st[j].ind=i;
    			}
    		}
    		//for(i=1;i<=n;i++){
    		//	printf("%d ", l[i]);
    		//}
    		//printf("\n");
    		long long int max=-1;
    		for(i=1;i<=n;i++){
    			if(((l[i]+r[i]+1)*a[i])>max){
    				max=(l[i]+r[i]+1)*a[i];
    			}
    		}
    		printf("%lld\n", max);
    		scanf("%d", &n);
    	}
    	return 0;
    } 
