    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[10004];
    long long ans;
    long long dfs(int v, int par){
      int count=0; 
      long long partial=0;
      for(int i=0;i<g[v].size();i++){
        if(g[v][i]!=par){
          count++;
          partial+=dfs(g[v][i], v);
        }
      }
     
      if(count==0){
        ans++;
        return 1;
      }
      ans+=count+1+partial;
      return count+1+partial;
     
    }
    int main(){
      int T;
      scanf("%d", &T);
      while(T--){
        ans=0;
        int n, u, v;
        scanf("%d", &n);
     
        for(int i=0;i<n;i++){
          g[i].clear();
        }
     
        for(int i=0;i<n-1;i++){
          scanf("%d %d", &u, &v);
          g[u].push_back(v);
          g[v].push_back(u);
        }
        long long pui=dfs(0, -1);
        printf("%lld\n", ans);
     
      }
      return 0;
    } 
