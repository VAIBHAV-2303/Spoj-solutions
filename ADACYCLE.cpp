    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[2005];
    int ans[2005];
    int root[2005];
    void bfs(int v){
        queue<pair<int, int> > q;
        q.push(make_pair(v, 1));
        int vis[2005]={0};
        vis[v]=1;
        root[v]=-1;
        pair<int, int> temp;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            for(int i=0;i<g[temp.first].size();i++){
                if(g[temp.first][i]==v){
                    while(v!=-1){
                        ans[v]=min(ans[v], temp.second);
                        v=root[v];
                    }
                    return;
                }
                if(vis[g[temp.first][i]]==0){
                    vis[g[temp.first][i]]=1;
                    root[g[temp.first][i]]=temp.first;
                    q.push(make_pair(g[temp.first][i], temp.second+1));
                }
            }
        }
        ans[v]=-1;
        return;
    }
    int main(){
     
        for(int i=0;i<2005;i++){
            ans[i]=200005;
        }
     
        int n, temp;
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d", &temp);
                if(temp==1){
                    g[i].push_back(j);
                }
            }
        }
     
        for(int i=1;i<=n;i++){
            if(ans[i]==200005){
                bfs(i);
                if(ans[i]==-1){
                    printf("NO WAY\n");
                }
                else{
                    printf("%d\n", ans[i]);
                }
            }
            else{
                printf("%d\n", ans[i]);
            }
        }
     
        return 0;
    } 
