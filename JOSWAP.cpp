    #include<bits/stdc++.h>
    using namespace std;
    int freq[100005], a[100005];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long ans=0;
    		for(int i=0;i<100005;i++){
    			freq[i]=0;
    		}
     
    		int n, flag=0;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    			freq[a[i]]++;
    			if(freq[a[i]]==2){
    				ans=1;
    			}
    		}
     
    		for(int i=0;i<n;i++){
    			freq[a[i]]--;
    			ans+=((n-i-1)-freq[a[i]]);
    			// printf("%lld\n", ans);
    		}
    		printf("%lld\n", ans);
     
    	}
    	return 0;
    } 
