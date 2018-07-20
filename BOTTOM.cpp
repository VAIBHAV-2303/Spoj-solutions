    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[5005];
    vector<int> gg[5005];
    int vis[5005];
    stack<int> gs;
    int ans[5005];
    set<int> rej;
    set<int>::iterator it;
    void dfsg(int ver){
    	vis[ver]=1;
    	for(int i=0;i<g[ver].size();i++){
    		if(vis[g[ver][i]]==0){
    			dfsg(g[ver][i]);
    		}
    	}
    	gs.push(ver);
    }
    void dfsgg(int ver, int curr){
    	ans[ver]=curr;
    	vis[ver]=1;
    	for(int i=0;i<gg[ver].size();i++){
    		if(vis[gg[ver][i]]==0){
    			dfsgg(gg[ver][i], curr);
    		}
    	}
    }
    int main(){
    	while(1){
    		for(int i=0;i<5005;i++){
    			g[i].clear();
    			gg[i].clear();
    			vis[i]=0;
    			ans[i]=0;
    		}
    		rej.clear();
    		int n, m, u, v;
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
    		scanf("%d", &m);
    		while(m--){
    			scanf("%d %d", &u, &v);
    			g[u].push_back(v);
    			gg[v].push_back(u);
    		}
     
    		for(int i=1;i<=n;i++){
    			if(vis[i]==0){
    				dfsg(i);
    			}	
    		}
     
    		for(int i=1;i<=n;i++){
    			vis[i]=0;	
    		}
     
    		int t=1;
     
    		while(!gs.empty()){
    			u=gs.top();
    			gs.pop();
    			if(vis[u]==0){
    				dfsgg(u, t);
    				t++;
    			}
    		}
     
    		for(int i=1;i<=n;i++){
    			t=ans[i];
    			it=rej.find(t);
    			if(it==rej.end()){
    				for(int j=0;j<g[i].size();j++){
    					if(ans[g[i][j]]!=t){
    						rej.insert(t);
    						break;
    					}
    				}
    			}
    		}
     
    		for(int i=1;i<=n;i++){
    			t=ans[i];
    			it=rej.find(t);
    			if(it==rej.end()){
    				printf("%d ", i);
    			}
    		}
    		printf("\n");
     
     
    	}
    	return 0;
    } 
