    #include<bits/stdc++.h>
    using namespace std;
    int main (){
    	int n, a[100005];
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    	}
     
    	sort(a, a+n);
    	long long ans=0;
     
    	for(int i=n-2;i>1;i-=2){
    		ans+=(a[1]+a[0]+a[i+1]+a[1]);
    	}
     
    	if(n%2==0){
    		ans+=a[1];
    	}
    	else{
    		ans+=a[1]+a[0]+a[2];
    	}
    	printf("%lld\n", ans);
    	return 0;
    } 