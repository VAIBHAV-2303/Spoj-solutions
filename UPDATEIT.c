    #include<stdio.h>
    long long a[10005];
    long long b[10005];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, u, l, r, q;
    		long long val;
    		scanf("%d %d", &n, &u);
    		for(int i=0;i<10005;i++){
    			a[i]=0;
    			b[i]=0;
    		}
     
    		while(u--){
    			scanf("%d %d %lld", &l, &r, &val);
    			b[l]+=val;
    			b[r+1]-=val;
    		}
    		val=0;
    		for(int i=0;i<n;i++){
    			val+=b[i];
    			a[i]=val;
    		}
    		scanf("%d", &q);
    		while(q--){
    			scanf("%d", &u);
    			printf("%lld\n", a[u]);
    		}
     
    	}
    	return 0;
    } 
