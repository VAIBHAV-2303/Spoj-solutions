    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[50004];
    int ind[50004], info[50004], ans;
    void fn(int v){
    	for(int i=0;i<g[v].size();i++){
    		info[g[v][i]]++;
    		if(info[g[v][i]]==ind[g[v][i]]+1){
    			ans++;
    			fn(g[v][i]);
    		}
    	}
    }
    int main(){
    	int n, m;
    	while(scanf("%d %d", &n, &m)!=EOF){
    		for(int i=0;i<50004;i++){
    			g[i].clear();
    			ind[i]=0;
    			info[i]=0;
    		}
    		int u, v;
    		while(m--){
    			scanf("%d %d", &u, &v);
    			g[u].push_back(v);
    			ind[v]++;
    		}
    		ans=0;
    		for(int i=0;i<n;i++){
    			scanf("%d", &u);
    			info[u]++;
    			if(info[u]==ind[u]+1){
    				ans++;
    				fn(u);
    			}
    			printf("%d\n", ans);
    		}
    	}
    	return 0;
    } 