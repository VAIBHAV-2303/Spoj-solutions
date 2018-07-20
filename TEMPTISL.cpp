    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int n, b;
    long long int dp[55][55];
    long long fn(int a, int k){
        // printf("%d %d\n", a, k);
        if(dp[a][k]==-1){
            if(a==n+1){
                return fn(1, k);
            }
            else if(a==0){
                return fn(n, k);
            }
            else{
                if(k==0 && a==b){
                    dp[a][k]=1;
                }
                else if(k==0 && a!=b){
                    dp[a][k]=0;
                }
                else{
                    dp[a][k]=fn(a-1, k-1)+fn(a+1, k-1);
                }
            }
        }
        return dp[a][k];
    }
    int main(){
        int k, a;
        while(1){
            for(int i=0;i<55;i++){
                for(int j=0;j<55;j++){
                    dp[i][j]=-1;
                }
            }
     
            scanf("%d %d", &n, &k);
            if(n==-1 && k==-1){
                break;
            }
            scanf("%d %d", &a, &b);
     
            printf("%lld\n", fn(a, k));
     
        }
        return 0;
    } 
