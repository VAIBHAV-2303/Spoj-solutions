    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long aux[300005];
    long long dp[300005];
    int n;
    long long fn(int v){
            if(dp[v]==-1){
                    if(v>=3*n){
                            dp[v]=100000000000000;
                    }
                    else if(v==3*n-2){
                            dp[v]=aux[v];
                    }
                    else if(v%3==0){
                            dp[v]=aux[v]+min(fn(v+1), min(fn(v+3), fn(v+4)));
                    }
                    else if(v%3==1){
                            dp[v]=aux[v]+min(fn(v+1), min(fn(v+2), min(fn(v+3), fn(v+4))));
                    }
                    else{
                            dp[v]=aux[v]+min(fn(v+3), fn(v+2));
                    }        
            }
            return dp[v];
    }
    int main(){
            for(int t=1;true;t++){
                    for(int i=0;i<300005;i++){
                            dp[i]=-1;
                    }
     
                    scanf("%d", &n);
                    if(n==0){
                            return 0;
                    }
     
                    for(int i=0;i<3*n;i++){
                            scanf("%lld", &aux[i]);
                    }
     
                    printf("%d. %lld\n", t, fn(1));
     
            }
    } 
