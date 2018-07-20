    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[1005], gd[1005];
    int vis[1005], outd[1005], which[1005];
    stack<int> st;
    void dfs(int ver){
    	vis[ver]=1;
    	for(int i=0;i<g[ver].size();i++){
    		if(vis[g[ver][i]]==0){
    			dfs(g[ver][i]);
    		}
    	}
    	st.push(ver);
    }
    void create(int ver, int s){
    	which[ver]=s;
    	vis[ver]=1;
    	for(int i=0;i<gd[ver].size();i++){
    		if(vis[gd[ver][i]]==0){
    			create(gd[ver][i], s);
    		}
    	}
    }
    void final(int ver){
    	vis[ver]=1;
    	for(int i=0;i<g[ver].size();i++){
    		if(which[ver]!=which[g[ver][i]]){
    			// printf("%d\n", ver);
    			outd[which[ver]]++;
    		}
    		if(vis[g[ver][i]]==0){
    			final(g[ver][i]);
    		}
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
     
    		for(int i=0;i<1005;i++){
    			g[i].clear();
    			gd[i].clear();
    			vis[i]=0;
    			outd[i]=0;
    			which[i]=0;
    		}
     
    		int n, m, u, v;
    		scanf("%d", &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d", &m);
    			while(m--){
    				scanf("%d", &v);
    				g[i].push_back(v);
    				gd[v].push_back(i);
    			}
    		}
     
    		for(int i=1;i<=n;i++){
    			if(vis[i]==0){
    				dfs(i);
    			}
    		}
    		for(int i=0;i<=n;i++){
    			vis[i]=0;
    		}
    		int t=1;
    		for(int i=1;i<=n;i++){
    			if(vis[st.top()]==0){
    				// printf("%d\n", st.top());
    				create(st.top(), t);
    				t++;
    			}
    			st.pop();
    		}
     
    		for(int i=0;i<=n;i++){
    			vis[i]=0;
    		}
     
    		for(int i=1;i<=n;i++){
    			if(vis[i]==0){
    				final(i);
    			}
    		}
     
    	// answer
    		int ans, count=0;
    		for(int i=1;i<t;i++){
    			if(outd[i]==0){
    				ans=i;
    				count++;
    			}
    		}
    		if(count>=2){
    			printf("0\n");
    			continue;
    		}
    		count=0;
    		for(int i=1;i<=n;i++){
    			if(which[i]==ans){
    				count++;
    			}
    		}
    		printf("%d\n", count);
    	}
    	return 0;
    } 
