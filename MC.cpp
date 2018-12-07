    #include<bits/stdc++.h>
    using namespace std;
    #include<string.h>
    int dp[1003][1003];
    char s1[1003], s2[1003];
    int lcs(int x, int y){
        if(x<0 || y<0){
            return 0;
        }
     
        if(dp[x][y]==-1){
            if(s1[x]==s2[y]){
                dp[x][y]=1+lcs(x-1, y-1);
            }
            else{
                dp[x][y]=max(lcs(x-1, y), lcs(x, y-1));
            }
        }
        return dp[x][y];
    }
    int main(){
        while(1){
            scanf("%s", s1);
            if(s1[0]=='#'){
                return 0;
            }
            scanf("%s", s2);
            int n=strlen(s1), m=strlen(s2);
            for(int i=0;i<n+3;i++){
                for(int j=0;j<m+3;j++){
                    dp[i][j]=-1;
                }
            }
            int l = lcs(n-1, m-1);
            printf("%d\n", 15*(n-l)+30*(m-l));
        }
    } 