    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
        int ver;
        int len;
    }node;
    int p[100005][20];
    int maxi[100005][20];
    int mini[100005][20];
    int l[100005];
    vector<node> G[100005];
    void dfs(int ver, int lev, int par, int edge){
        l[ver]=lev;
        p[ver][1]=par;
        maxi[ver][1]=edge;
        mini[ver][1]=edge;
        for(int i=0;i<G[ver].size();i++){
            if(G[ver][i].ver!=par){
                dfs(G[ver][i].ver, lev+1, ver, G[ver][i].len);
            }
        }
    }
    int main(){
        int n, u, v, q, curmin, curmax;
        scanf("%d", &n);
        node temp;
        for(int i=0;i<n-1;i++){
            scanf("%d %d %d", &u, &v, &temp.len);
            temp.ver=v;
            G[u].push_back(temp);
            temp.ver=u;
            G[v].push_back(temp);
        }
     
        for(int i=1;i<=n;i++){
            p[i][0]=i;
            maxi[i][0]=-1;
            mini[i][0]=10000000;
        }
     
        dfs(1, 0, -1, -1);
     
        for(int j=2;(1<<j)<n;j++){
            for(int i=1;i<=n;i++){
                if(p[i][j-1]>=1){
                    maxi[i][j]=max(maxi[i][j-1], maxi[p[i][j-1]][j-1]);
                    mini[i][j]=min(mini[i][j-1], mini[p[i][j-1]][j-1]);
                    p[i][j]=p[p[i][j-1]][j-1];
                }
            }
        }
     
        scanf("%d", &q);
        while(q--){
            curmax=-1;
            curmin=10000000;
            scanf("%d %d", &u, &v);
            if(l[v]>l[u]){
                while(l[u]<l[v]){
                    int j=0;
                    while(p[v][j+1]>=1 && l[p[v][j+1]]>=l[u]){
                        j++;
                    }
                    curmax=max(curmax, maxi[v][j]);
                    curmin=min(curmin, mini[v][j]);
                    v=p[v][j];
                }
            }
            else if(l[u]>l[v]){
                while(l[v]<l[u]){
                    int j=0;
                    while(p[u][j+1]>=1 && l[p[u][j+1]]>=l[v]){
                        j++;
                    }
                    curmax=max(curmax, maxi[u][j]);
                    curmin=min(curmin, mini[u][j]);
                    u=p[u][j];
                }
            }
            // printf("pui\n");
            while(v!=u){
                int j=0;
                while(p[u][j+1]!=p[v][j+1]){
                    j++;
                }
                if(j==0){
                    j++;
                }
                curmax=max(curmax, max(maxi[u][j], maxi[v][j]));
                curmin=min(curmin, min(mini[u][j], mini[v][j]));
                u=p[u][j];
                v=p[v][j];
            }
            printf("%d %d\n", curmin, curmax);
        }
        return 0;
    } 
