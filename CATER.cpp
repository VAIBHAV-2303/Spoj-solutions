    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[2503];
    int stc[2503][92]={0}, aux[92];
    int m=10243;
    void fn(int par, int ver){
    	for(int i=0;i<92;i++){
    		aux[i]=stc[par][i];
    	}
    	for(int i=0;i<92;i++){
    		for(int j=0;j<=i;j++){
    			stc[par][i]=(stc[par][i]+ ((1LL*aux[i-j]*stc[ver][j])%m) )%m;
    		}
    	}
    }
    void dfs(int ver, int par){
    	stc[ver][1]=1;
    	for(int i=0;i<g[ver].size();i++){
    		if(g[ver][i]!=par){
    			dfs(g[ver][i], ver);
    			fn(ver, g[ver][i]);
    		}
    	}
    }
    int main(){
    	int n, k, u, v, ans=0;
    	scanf("%d %d", &n, &k);
    	for(int i=0;i<n-1;i++){
    		scanf("%d %d", &u, &v);
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
    	dfs(1, -1);
    	for(int i=1;i<=n;i++){
    		ans=(ans+stc[i][k])%m;
    	}
    	printf("%d\n", ans);
     
    } 
