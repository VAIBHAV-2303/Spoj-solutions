    #include<bits/stdc++.h>
    using namespace std;
    pair<int, int> a[1003];
    int dp[1003][1003], n, x[1003][1003], y[1003][1003];
    int fnx(int mini, int maxi){
        if(mini==maxi){
            return 0;
        }
        if(x[mini][maxi]==-1){
            if(a[maxi].second<a[mini].second){
                x[mini][maxi]=1+fnx(mini, maxi-1);
            }
            else{
                x[mini][maxi]=fnx(mini, maxi-1);
            }
        }
        return x[mini][maxi];
    }
    int fny(int mini, int maxi){
        if(mini==maxi){
            return 0;
        }
        if(y[mini][maxi]==-1){
            if(a[mini].second<a[maxi].second){
                y[mini][maxi]=1+fny(mini+1, maxi);
            }
            else{
                y[mini][maxi]=fny(mini+1, maxi);
            }
        }
        return y[mini][maxi];
    }
    int dpfn(int mini, int maxi){
        if(dp[mini][maxi]==-1){
            if(mini==maxi){
                dp[mini][maxi]=a[mini].second;
            } 
            else{
                dp[mini][maxi]=min(dpfn(mini+1, maxi) + (maxi-mini+1)*(a[mini].second-fnx(mini, maxi))\
                                , dpfn(mini, maxi-1) + (maxi-mini+1)*(a[maxi].second-fny(mini, maxi)) );
            }
        }  
        return dp[mini][maxi];
    }
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            for(int i=0;i<1003;i++){
                for(int j=0;j<1003;j++){
                    dp[i][j]=-1;
                    x[i][j]=-1;
                    y[i][j]=-1;
                }
            }
     
            scanf("%d", &n);
            for(int i=1;i<=n;i++){
                scanf("%d", &a[i].first);
                a[i].second=i;
            }
            sort(a+1, a+n+1);
            printf("%d\n", dpfn(1, n));
        }
        return 0;
    } 