    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    pair<int, int> a[10004];
    long long cum[10004], pui[10004], bpui[10004], bcum[10004];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i].first);
    		}
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i].second);
    		}
     
    		sort(a, a+n);
     
    		cum[0]=a[0].second;
    		for(int i=1;i<n;i++){
    			cum[i]=cum[i-1]+a[i].second;
    		}
     
    		bcum[n-1]=a[n-1].second;
    		for(int i=n-2;i>=0;i--){
    			bcum[i]=bcum[i+1]+a[i].second;
    		}
     
    		pui[0]=0;
    		for(int i=1;i<n;i++){
    			pui[i]=pui[i-1]+cum[i-1]*(a[i].first-a[i-1].first);
    			// printf("%lld\n", pui[i]);
    		}
     
    		bpui[n-1]=0;
    		for(int i=n-2;i>=0;i--){
    			bpui[i]=bpui[i+1]+bcum[i+1]*(a[i+1].first-a[i].first);
    		}
     
    		long long ans=10000000000000000;
    		for(int i=0;i<n;i++){
    			if(pui[i]+bpui[i]<ans){
    				ans=pui[i]+bpui[i];
    			}
    		}
    		printf("%lld\n", ans);
    	}
    	return 0;
    } 
