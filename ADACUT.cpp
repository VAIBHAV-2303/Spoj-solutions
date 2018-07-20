    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long a[300005];
    long long csum[300005];
    int main(){
    	int n;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%lld", &a[i]);
    	}
     
    	sort(a, a+n);
     
    	if(a[0]==a[n-1]){
    		printf("0\n");
    		return 0;
    	}
     
    	csum[0]=a[0];
    	for(int i=1;i<n;i++){
    		csum[i]=a[i]+csum[i-1];
    	}
    	long long currmin=csum[n-1]-csum[0]-(n-1)*a[0];
    	for(int i=1;i<n;i++){
    		if(csum[n-1]-csum[i]-(n-i-1)*a[i]+csum[i-1]<currmin){
    			currmin=csum[n-1]-csum[i]-(n-i-1)*a[i]+csum[i-1];
    		}
    	}
    	printf("%lld\n", currmin);
    	return 0;
    } 
