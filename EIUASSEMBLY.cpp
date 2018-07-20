    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    pair<long long, long long> a[100005];
    long long cum[100005];
    long long bins[100005];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		long long m;
    		scanf("%d %lld", &n, &m);
    		for(int i=0;i<n;i++){
    			scanf("%lld %lld", &a[i].first, &a[i].second);
    		}
    		sort(a, a+n);
    		
    		cum[0]=a[0].second;
    		for(int i=1;i<n;i++){
    			cum[i]=cum[i-1]+a[i].second;
    		}
     
    		bins[0]=0;
    		for(int i=1;i<n;i++){
    			bins[i]=bins[i-1]+cum[i-1]*(a[i].first-a[i-1].first);
    		}
     
    		if(m>bins[n-1]){
    			// printf("pui\n");
    			printf("%lld\n", a[n-1].first+(m-bins[n-1])/cum[n-1]);
    			continue;
    		}
     
    		for(int i=0;i<n;i++){
    			if(bins[i]==m){
    				printf("%lld\n", a[i].first);
    				break;
    			}
    			else if(bins[i]>m){
    				printf("%lld\n", a[i-1].first+(m-bins[i-1])/cum[i-1]);
    				break;
    			}
    		}
     
    	}
    	return 0;
    } 
