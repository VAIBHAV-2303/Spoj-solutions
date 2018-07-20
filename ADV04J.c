    #include<stdio.h>
    using namespace std;
    int dp[1000006];
    int fn(int n){
        if(dp[n]==-1){
            dp[n]=1+fn((n+1)/2);
        }
        return dp[n];
    }
    int main(){
        int T;
        scanf("%d", &T);
        for(int i=0;i<1000006;i++){
            dp[i]=-1;
        }
        dp[3]=3;
        dp[4]=3;
        while(T--){
            int n;
            scanf("%d", &n);
            printf("%d\n", fn(n));
        }
        return 0;
    } 
