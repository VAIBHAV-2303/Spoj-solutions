#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int arr[50];
long long dp[4408][50][11];
long long fn(int n, int x, int k){
	x=max(x, 0);
	if(k>n+1){
		return 0;
	}
	if(dp[x][n][k]==-1){
		if(k==1){
			int count=0;
			for(int i=0;i<=n;i++){
				if(arr[i]>=x){
					count++;
				}
			}
			dp[x][n][k]=count;
		}
		else{
			dp[x][n][k]=fn(n-1, x, k)+fn(n-1, x-arr[n], k-1);
		}
	}
	return dp[x][n][k];
}
int main(){
	int t, x;
	for(int i=0;i<100;i++){
		for(int j=0;j<44;j++){
			scanf("%d", &x);
			if(x){
				arr[j]++;
			}
		}
	}
	for(int i=0;i<4408;i++){
		for(int j=0;j<50;j++){
			for(int u=0;u<11;u++){
				dp[i][j][u]=-1;
			}
		}
	}

	scanf("%d", &x);
	if(x>4405){
		printf("0\n");
		return 0;
	}

	printf("%lld\n", fn(43, x, 10));

}
