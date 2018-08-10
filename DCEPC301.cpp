    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int a[3005], dp[3005][3005];
    int fn(int l, int r){
    	if(dp[l][r]==-1){
    		if(r<l){
    			dp[l][r]=0;
    		}
    		else if(r==l+1){
    			dp[l][r]=2*max(a[l], a[r]);
    		}
    		else if(r==l){
    			dp[l][r]=2*a[l];
    		}
    		else{
    			int n=r-l+1, var;
    			var=2*a[l+(n/2)]+2*fn(l+(n/2)+1, r);
    			var=max(var, 2*a[l+(n/2)]+2*fn(l, l+(n/2)-1));
    			var=max(var, 2*a[l+(n/2)+1]+2*fn(l+(n/2)+2, r));
    			var=max(var, 2*a[l+(n/2)+1]+2*fn(l, l+(n/2)));
    			dp[l][r]=var;
    		}
    	}
    	return dp[l][r];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		for(int i=0;i<3005;i++){
    			for(int j=0;j<3005;j++){
    				dp[i][j]=-1;
    			}
    		}
     
    		int n;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
    		printf("%d\n", fn(0, n-1)>>1);
    	}
    } 
