    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int a[1005];
    int dp[1005][1005];
    int fn(int l, int r){
    	if(dp[l][r]==-1){
    		if(r-l==1){
    			dp[l][r]=max(a[l]-a[r], a[r]-a[l]);
    		}	
    		else{
    			if(a[l+1]>=a[r]){
    				if(a[l]>=a[r-1]){
    					dp[l][r]=max(a[l]-a[l+1]+fn(l+2, r), a[r]-a[l]+fn(l+1, r-1));
    				}
    				else{
    					dp[l][r]=max(a[l]-a[l+1]+fn(l+2, r), a[r]-a[r-1]+fn(l, r-2));
    				}
    			}	
    			else{
    				if(a[l]>=a[r-1]){
    					dp[l][r]=max(a[l]-a[r]+fn(l+1, r-1), a[r]-a[l]+fn(l+1, r-1));
    				}
    				else{
    					dp[l][r]=max(a[l]-a[r]+fn(l+1, r-1), a[r]-a[r-1]+fn(l, r-2));
    				}
    			}
    		}
    	}
    	return dp[l][r];
    }
    int main(){
    	for(int t=1;t<100000;t++){
    		int n;
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		for(int i=0;i<1004;i++){
    			for(int j=0;j<1004;j++){
    				dp[i][j]=-1;
    			}
    		}
    		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", t, fn(0, n-1));
    	}
    	return 0;
    } 
