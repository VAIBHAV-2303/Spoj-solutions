    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int T;
        scanf("%d", &T);
        int n, t;
        int dp[254][105], time[105][105], tolls[105][105];
        while(T--){
            scanf("%d %d", &n, &t);
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
     
            if(dp[t][n-1]==10000000){
                printf("-1\n");
                continue;
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
