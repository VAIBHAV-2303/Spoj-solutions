    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T, a[53], b[53];
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int n;
    		long long ans=0;
    		scanf("%d", &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d", &a[i]);
    		}
    		sort(a+1, a+n+1);
    		if(n%2==1){
    			for(int i=0;i<n/2;i++){
    				b[2*i]=a[(n/2)-i];
    				b[2*i+1]=a[n-i];
    			}
    			if(a[(n/2)+1]-a[n/2]>a[(n/2)+2]-a[(n/2)+1]){
    				ans+=a[(n/2)+1]-a[n/2];
    			}
    			else{
    				ans+=a[(n/2)+2]-a[(n/2)+1];
    			}
    		}
    		else{
    			for(int i=0;i<n/2;i++){
    				b[2*i]=a[(n/2)-i];
    				b[2*i+1]=a[n-i];
    			}	
    		}
     
    		if(n%2==1){
    			for(int i=0;i<n-2;i++){
    				ans+=(abs(b[i]-b[i+1]));
    			}
    		}
    		else{
    			for(int i=0;i<n-1;i++){
    				ans+=(abs(b[i]-b[i+1]));
    			}
    		}
     
    		printf("Case %d: %lld\n", t, ans);
    	}
    	return 0;
    } 