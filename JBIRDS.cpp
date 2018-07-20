    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int dp[10004][10004];
    int a[10004];
    int main(){
    	int n, total=0, half;
    	scanf("%d", &n);
    	for(int i=1;i<=n;i++){
    		scanf("%d", &a[i]);
    		total+=a[i];
    	}
    	half=total/2;
    	// printf("%d\n", half);
    	for(int i=0;i<=n;i++){
    		dp[0][i]=0;
    	}
    	for(int i=0;i<=half;i++){
    		dp[i][0]=0;
    	}
     
    	for(int i=1;i<=half;i++){
    		for(int j=1;j<=n;j++){
    			if(i-a[j]<0){
    				dp[i][j]=dp[i][j-1];
    			}
    			else{
    				dp[i][j]=max(dp[i][j-1], dp[i-a[j]][j-1]+a[j]);
    			}
    		}
    	}
     
    	printf("%d\n", total-2*dp[half][n]);
     
    	return 0;
    } 
