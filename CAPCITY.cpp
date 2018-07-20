    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[100005], gd[100005];
    int vis[100005]={0}, outd[100005]={0}, which[100005]={0};
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
    	int n, m, u, v;
    	scanf("%d %d", &n, &m);
    	while(m--){
    		scanf("%d %d", &u, &v);
    		g[u].push_back(v);
    		gd[v].push_back(u);
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
    	for(int i=1;i<=t;i++){
    		if(outd[i]==0){
    			ans=i;
    			break;
    		}
    	}
    	// printf("%d\n", ans);
    	for(int i=1;i<=n;i++){
    		if(which[i]==ans){
    			count++;
    		}
    	}
    	printf("%d\n", count);
    	for(int i=1;i<=n;i++){
    		if(which[i]==ans){
    			printf("%d ", i);
    		}
    	}
    	printf("\n");
    	return 0;
    } 
