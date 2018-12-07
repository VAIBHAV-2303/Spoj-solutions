    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[100005];
    vector<bool> arr (100005, true);
    int vis[100005];
    int dfs(int ver){
    	vis[ver]=1;
    	int partial=0;
    	for(int i=0;i<g[ver].size();i++){
    		if(vis[g[ver][i]]==0){
    			partial+=dfs(g[ver][i]);
    		}
    	}
    	return 1 + partial;
    }
    int main(){
     
    	arr[0]=false;
    	arr[1]=false;
    	for(int i=2;i*i<100005;i++){
    		if(arr[i] == true){
    			for(int j=i;j*i<100005;j++){
    				arr[j*i]=false;
    			}	
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		for(int i=0;i<100005;i++){
    			g[i].clear();
    			vis[i]=0;
    		}
     
    		int n, m, u, v, curmax=-1, pui;
    		scanf("%d %d", &n, &m);
     
    		while(m--){
    			scanf("%d %d", &u, &v);
    			g[u].push_back(v);
    			g[v].push_back(u);
    		}
     
    		for(int i=1;i<=n;i++){
    			if(vis[i]==0){
    				pui=dfs(i);
    				if(pui>curmax && arr[pui]==true){
    					curmax=pui;
    				}
    			}	
    		}
     
    		printf("%d\n", curmax);
     
    	}
    	return 0;
    } 