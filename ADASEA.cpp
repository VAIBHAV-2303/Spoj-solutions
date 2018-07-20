    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    char a[1003][1003];
    int vis[1003][1003];
    vector<pair<int, int> >v;
    int n, m;
    long long temp;
    long long gcd(long long x, long long y){
        if(x==0){
            return y;
        }
        return gcd(y%x, x);
    }
    void dfs(int x, int y){
        if(x<0 || x>=n || y<0 || y>=m || a[x][y]=='~'){
            return;
        }
     
        vis[x][y]=1;
        temp++;
        if(vis[x-1][y]==0){
            dfs(x-1, y);
        }
        if(vis[x+1][y]==0){
            dfs(x+1, y);   
        }
        if(vis[x][y-1]==0){
            dfs(x, y-1);
        }
        if(vis[x][y+1]==0){
            dfs(x, y+1);
        }
    }
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            v.clear();
            long long ans=0;
            scanf("%d %d", &n, &m);
            
            for(int i=0;i<n;i++){
                scanf("%s", a[i]);
            }
     
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    vis[i][j]=0;
                    if(a[i][j]=='#'){
                        v.push_back(make_pair(i, j));
                    }
                }
            }
     
            for(int i=0;i<v.size();i++){
                if(vis[v[i].first][v[i].second]==0){
                    temp=0;
                    dfs(v[i].first, v[i].second);
                    ans+=temp*temp;
                }
            }
     
            if(ans==0){
                printf("0\n");
            }
            else if((ans)%(m*n)==0){
                printf("%lld\n", ans/(m*n));
            }
            else{
                printf("%lld / %lld\n", ans/gcd(ans, m*n), m*n/gcd(ans, m*n));
            }
        }
        return 0;
    } 
