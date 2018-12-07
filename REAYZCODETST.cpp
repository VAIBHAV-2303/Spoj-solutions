    #include<bits/stdc++.h>
    using namespace std;
    int a[100005];
    int main(){
    	int T, n, x;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		scanf("%d %d", &n, &x);
    		long long ans=0;
     
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		sort(a, a+n);
     
    		for(int i=0;i<n-1;i++){	
    			ans+=( (upper_bound(a+i+1, a+n, a[i]+x) )-(lower_bound(a+i+1, a+n, a[i]+x))); 
    		}
     
    		if(x==0){
    			printf("Case %d: %lld\n", t, ans<<1);
    		}
    		else{
    			printf("Case %d: %lld\n", t, ans);
    		}
    	}
    	return 0;
    } 