    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int status[2005];
    vector<int> g[2005];
    int flag;
    void dfs(int ind, int par, int stat){
    	if(status[ind]==-1){
    		status[ind]=stat;
    		for(int i=0;i<g[ind].size();i++){
    			if(g[ind][i]!=par){
    				dfs(g[ind][i], ind, 1-stat);
    			}
    		}
    	}
    	else{
    		if(status[ind]!=stat){
    			flag=0;
    		}
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		flag=1;
    		for(int i=0;i<2005;i++){
    			g[i].clear();
    			status[i]=-1;
    		}
     
    		int n, u, v;
    		long long E;
    		scanf("%d %lld", &n, &E);
     
    		while(E--){
    			scanf("%d %d", &u, &v);
    			g[u].push_back(v);
    			g[v].push_back(u);
    		}
    		printf("Scenario #%d:\n", t);
    		
    		for(int i=1;i<=n;i++){
    			if(status[i]==-1){
    				dfs(i, -1, 0);
    			}
    		}
     
    		if(flag==0){
    			printf("Suspicious bugs found!\n");
    		}
    		else{
    			printf("No suspicious bugs found!\n");
    		}
     
    	}
    	return 0;
    } 
