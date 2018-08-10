    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int m=10007, dp[2003][3003], factarr[2003];
    int fn(int n, int k){
        k=max(k, 0);
        if(dp[n][k]==-1){
            if(k==0){
                dp[n][k]=factarr[n];
            }
            else if(n==0){
                dp[n][k]=0;
            }   
            else{
                int partial=0;
                partial=(partial+fn(n, k-1))%m;
                partial=(partial+fn(n-1, k))%m;
                partial=(partial - fn(n-1, k-(n)) + m)%m;
                dp[n][k]=partial;
            }
        }
        return dp[n][k];
    }
    int main(){
        factarr[0]=1;
        for(int i=1;i<2003;i++){
            factarr[i]=(1LL*i*factarr[i-1])%m;
        }
        for(int i=0;i<2003;i++){
            for(int j=0;j<3003;j++){
                dp[i][j]=-1;
            }
        }
        
        int T;
        scanf("%d", &T);
        for(int t=1;t<=T;t++){
            int n, k;
            scanf("%d %d", &n, &k);
            printf("Case %d: %d\n", t, fn(n, k));
        }
        return 0;
    } 
