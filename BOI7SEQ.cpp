    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int n, a[1000006];
    	long long ans=0;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    	}
    	
    	if(n==1){
    		printf("0\n");
    		return 0;
    	}
     
    	for(int i=0;i<n;i++){
    		if(i==0){
    			if(a[i]>=a[i+1]){
    				ans+=a[i];
    			}
    		}
    		else if(i==n-1){
    			if(a[i]>a[i-1]){
    				ans+=a[i];
    			}
    		}
    		else{
    			if(a[i]>a[i-1]){
    				ans+=a[i];
    			}
    			if(a[i]>=a[i+1]){
    				ans+=a[i];
    			}
    		}
    	}
     
    	printf("%lld\n", ans);
     
    	return 0;
    } 