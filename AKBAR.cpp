    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int vis[1000006];
    pair<int, int> sold[1000006];
    vector<int> G[1000006];
    int flag;
    void dfs(int papa, int k, int s, int par){
        if(vis[k]>0 && vis[k]!=papa){
            flag=1;
            return;
        }
        else{
            vis[k]=papa;
            if(s==0){
                return;
            }
            else{
                for(int i=0;i<G[k].size();i++){
                    if(G[k][i]!=par){
                        dfs(papa, G[k][i], s-1, k);
                    }
                }
            }
        }
    }
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            flag=0;
            for(int i=0;i<1000006;i++){
                vis[i]=0;
                G[i].clear();
            }
     
            int n, r, m, u, v;
            scanf("%d %d %d", &n, &r, &m);
            while(r--){
                scanf("%d %d", &u, &v);
                G[u].push_back(v);
                G[v].push_back(u);
            }
     
            for(int i=0;i<m;i++){
                scanf("%d %d", &sold[i].first, &sold[i].second);
            }
     
            for(int i=0;i<m;i++){
                dfs(sold[i].first, sold[i].first, sold[i].second, -1);
                if(flag){
                    printf("No\n");
                    break;
                }
            }
            if(flag==0){
                for(int i=1;i<=n;i++){
                    if(vis[i]==0){
                        printf("No\n");
                        flag=1;
                        break;
                    }
                }
            }
            
            if(flag==0){
                printf("Yes\n");
            }
        }
        return 0;
    } 
