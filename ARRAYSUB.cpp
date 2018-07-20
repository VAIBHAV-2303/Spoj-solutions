    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long a[100005];
    long long l[100005];
    long long r[100005];
    int main(){
    	int n, k, count;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%lld", &a[i]);
    	}
    	scanf("%d", &k);
     
    	for(int i=0;i<n;i++){
    		if(i%k==0){
    			l[i]=a[i];
    		}
    		else{
    			l[i]=max(l[i-1], a[i]);
    		}
    	}
     
    	for(int i=n-1;i>=0;i--){
    		if((i+1)%k==0){
    			r[i]=a[i];
    		}
    		else{
    			r[i]=max(r[i+1], a[i]);
    		}
    	}
     
    	for(int i=0;i<n-k+1;i++){
    		printf("%lld ", max(r[i], l[i+k-1]));
    	}
    	printf("\n");
    	return 0;
    } 
