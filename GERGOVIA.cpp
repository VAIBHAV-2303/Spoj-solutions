    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int a[100005];
    int main(){
    	while(1){
    		int n;
    		long long ans=0;
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
     
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		for(int i=0;i<n-1;i++){
    			ans+=abs(a[i]);
    			a[i+1]+=a[i];
    			// printf("%lld\n", ans);
    		}
    		printf("%lld\n", ans);
     
    	}
    	return 0;
    } 
