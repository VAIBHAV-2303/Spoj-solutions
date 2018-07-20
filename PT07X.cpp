    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> G[100005];
    int ans=0;
    int dfs(int ver, int par){
    	int flag=0;
    	for(int i=0;i<G[ver].size();i++){
    		if(G[ver][i]!=par){
    			if(dfs(G[ver][i], ver)==0){
    				flag=1;
    			}
    		}
    	}
    	if(flag){
    		ans++;
    		return 1;
    	}
    	return 0;
    }
    int main(){
    	int n, u, v;
    	scanf("%d", &n);
    	for(int i=0;i<(n-1);i++){
    		scanf("%d %d", &u, &v);
    		G[u].push_back(v);
    		G[v].push_back(u);
    	}
    	int pui=dfs(1, -1);
     
    	printf("%d\n", ans);
     
    	return 0;
    } 
