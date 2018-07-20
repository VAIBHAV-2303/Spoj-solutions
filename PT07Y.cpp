    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[10005];
    int vis[10005]={0};
    int flag=0;
    void dfs(int ver, int par){
    	if(vis[ver]==0){
    		vis[ver]=1;
    		for(int i=0;i<g[ver].size();i++){
    			if(g[ver][i]!=par){
    				dfs(g[ver][i], ver);
    			}
    		}
    	}
    	else{
    		flag=1;
    	}
    }
    int main(){
    	int n, m, u, v;
    	scanf("%d %d", &n, &m);
     
    	for(int i=0;i<m;i++){
    		scanf("%d %d", &u, &v);
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	if(m!=n-1){
    		printf("NO\n");
    		return 0;
    	}
     
    	dfs(1, -1);
     
    	if(flag==1){
    		printf("NO\n");
    		return 0;
    	}
    	else{
    		for(int i=1;i<=n;i++){
    			if(vis[i]==0){
    				printf("NO\n");
    				return 0;
    			}
    		}
    		printf("YES\n");
    	}
     
    	return 0;
    } 
