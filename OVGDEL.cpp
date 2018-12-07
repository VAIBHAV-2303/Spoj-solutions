    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	long long int a[10004];
    	for(int t=1;t<=T;t++){
    		bitset<1000006> bs;
     
    		int n, ans=0;
    		long long x;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &a[i]);
    			bs[a[i]]=1;
    		}
     
    		if(n==1){
    			printf("Case %d: 0\n", t);
    			continue;
    		}
    		
    		sort(a, a+n);
     
    		if(a[0]==1){
    			if(a[1]==1){
    				printf("Case %d: %d\n", t, n);
    			}
    			else{
    				printf("Case %d: %d\n", t, n-1);
    			}
    			continue;
    		}
    		for(int i=0;i<n;i++){
    			if((i+1)<n && a[i+1]==a[i]){
    				while((i+1)<n && a[i+1]==a[i]){
    					ans++;
    					i++;
    				}
    				ans++;
    				continue;
    			}
    			x=a[i]*a[i];
    			while(x<1000006){
    				if(bs[x]==1){
    					ans++;
    					break;
    				}
    				x=(x*a[i]);
    			}
    		}
    		printf("Case %d: %d\n", t, ans);
    	}
    	return 0;
    } 