    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[100005];
    int m=1e9+7, ans[100005]={0}, xarr[100005]={0}, yarr[100005]={0};
    void firstdfs(int ver, int par, int x){
            x=(x+xarr[ver])%m;
            ans[ver]=(ans[ver]+x)%m;
            for(int i=0;i<g[ver].size();i++){
                    if(g[ver][i]!=par){
                            firstdfs(g[ver][i], ver, x);
                    }
            }
    }
    void seconddfs(int ver, int par, int cur, int add){
            cur=(cur+add)%m;
            ans[ver]=(ans[ver]+cur)%m;
            add=(add+yarr[ver])%m;
            for(int i=0;i<g[ver].size();i++){
                    if(g[ver][i]!=par){
                            seconddfs(g[ver][i], ver, cur, add);
                    }
            }
    }
    int main(){
            int n, u, v, x, y;
            scanf("%d", &n);
            for(int i=0;i<n-1;i++){
                    scanf("%d %d", &u, &v);
                    g[u].push_back(v);
                    g[v].push_back(u);
            }
     
            int q;
            scanf("%d", &q);
            while(q--){
                    scanf("%d %d %d", &u, &x, &y);
                    xarr[u]=(xarr[u]+x)%m;
                    yarr[u]=(yarr[u]+y)%m;
            }
     
            firstdfs(1, -1, 0);
            seconddfs(1, -1, 0, 0);
     
            for(int i=1;i<=n;i++){
                    printf("%d\n", ans[i]);
            }
            return 0;
    } 
