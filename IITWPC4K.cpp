    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[1000006], gd[1000006];
    int ind[1000006], n, vis[1000006];
    int checkcycle(){
            queue<int> q;
            for(int i=1;i<=n;i++){
                    if(ind[i]==0){
                            q.push(i);
                    }
            }
            int ver, count=0;
            while(!q.empty()){
                    count++;
                    ver=q.front();
                    q.pop();
                    for(int i=0;i<g[ver].size();i++){
                            ind[g[ver][i]]--;
                            if(ind[g[ver][i]]==0){
                                    q.push(g[ver][i]);
                            }
                    }
            }
            if(count==n){
                    return 0;
            }
            return 1;       
     
    }
    int dfspiche(int ver){
            vis[ver]=1;
            int partial=0;
            for(int i=0;i<gd[ver].size();i++){
                    if(vis[gd[ver][i]]==0){
                            partial+=dfspiche(gd[ver][i]);
                    }
            }
            return 1+partial;
    }
    int dfsaage(int ver){
            vis[ver]=1;
            int partial=0;
            for(int i=0;i<g[ver].size();i++){
                    if(vis[g[ver][i]]==0){
                            partial+=dfsaage(g[ver][i]);
                    }
            }
            return 1+partial;
    }
    int main(){
            int T;
            scanf("%d", &T);
            while(T--){
                    for(int i=0;i<1000006;i++){
                            g[i].clear();
                            gd[i].clear();
                            ind[i]=0;
                            vis[i]=0;
                    }
     
                    int m, k, u, v;
                    scanf("%d %d %d", &n, &m, &k);
                    while(m--){
                            scanf("%d %d", &u, &v);
                            g[u].push_back(v);
                            gd[v].push_back(u);
                            ind[v]++;
                    }
     
                    if(checkcycle()){
                            printf("-1\n");
                            continue;
                    }
     
                    int piche=dfspiche(k);
                    for(int i=0;i<=1000006;i++){
                            vis[i]=0;
                    }
                    int aage=dfsaage(k);
     
                    
                    printf("%d\n", n-aage-piche+2);
                    for(int i=0;i<n-aage-piche+2;i++){
                            printf("%d ", i+piche);
                    }
                    printf("\n");
     
            }
            return 0;
    }  
