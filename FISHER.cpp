    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int n, t;
        int dp[1004][55], time[55][55], tolls[55][55];
        while(1){
            scanf("%d %d", &n, &t);
            if(n==0 && t==0){
                break;
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    scanf("%d", &time[i][j]);
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    scanf("%d", &tolls[i][j]);
                }
            }
     
            for(int i=0;i<n;i++){
                dp[0][i]=10000000;
            }
            for(int i=0;i<=t;i++){
                dp[i][0]=0;
            }
     
            for(int i=1;i<=t;i++){
                for(int j=1;j<n;j++){
                    dp[i][j]=10000000;
                    for(int k=0;k<n;k++){
                        if(i-time[k][j]>=0){
                            dp[i][j]=min(dp[i][j], tolls[k][j]+dp[i-time[k][j]][k]);
                        }
                    }
                }
            }
     
            for(int j=0;j<=t;j++){
                if(dp[j][n-1]==dp[t][n-1]){
                    printf("%d %d\n", dp[j][n-1], j);
                    break;
                }
            }
     
        }
        return 0;
    } 
