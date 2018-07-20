    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[1000010];
    int ans[1000010];
    int dfs(int v, int par){
            int max1=0, max2=0, pui=par, temp;
            ans[v]=0;
            for(int i=0;i<g[v].size();i++){
                    if(g[v][i]!=par){
                            temp=1+dfs(g[v][i], v);
                            ans[v]=max(ans[v], ans[g[v][i]]);
                            if(temp>max1){
                                    max1=temp;
                                    pui=g[v][i];
                            }
                    }
            }
            for(int i=0;i<g[v].size();i++){
                    if(g[v][i]!=par && g[v][i]!=pui){
                            temp=1+dfs(g[v][i], v);
                            if(temp>max2){
                                    max2=temp;
                            }
                    }
            }
            ans[v]=max(ans[v], max1+max2);
            return max1;
    }
    int main(){
            int n, u, v, q;
            scanf("%d", &n);
            for(int i=0;i<n-1;i++){
                    scanf("%d %d", &u, &v);
                    g[u].push_back(v);
                    g[v].push_back(u);
            }
            scanf("%d", &u);
            int temp=dfs(u, -1);
            scanf("%d", &q);
            while(q--){
                    scanf("%d", &v);
                    printf("%d\n", ans[v]);
            }
            return 0;
    } 
