    #include<stdio.h>
    using namespace std;
    int a[10005];
    int main(){
    	while(1){
    		int n, avg;
    		long long total=0, ans=0;
    		scanf("%d", &n);
    		if(n==-1){
    			break;
    		}
     
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    			total+=a[i];
    		}	
     
    		if(total%n!=0){
    			printf("-1\n");
    			continue;
    		}
     
    		avg=total/n;
    		for(int i=0;i<n;i++){
    			if(a[i]<avg){
    				ans+=(avg-a[i]);
    			}
    		}
     
    		printf("%lld\n", ans);
     
    	}
    	return 0;
    } 
