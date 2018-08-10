    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<bool> arr(2000000, true);
    vector<int> primes, g[100005];
    int vis[100005];
    void generate(){
    	arr[0]=false;
    	arr[1]=false;
    	for(long long int i=2;i*i<2000000;i++){
    		if(arr[i]){
    			for(long long int j=i;j*i<2000000;j++){
    				arr[j*i]=false;
    			}
    		}
    	}
    	for(int i=0;i<2000000;i++){
    		if(arr[i]){
    			primes.push_back(i);
    		}
    	}
    }
    int dfs(int ver){
    	vis[ver]=1;
    	int partial=0;
    	for(int i=0;i<g[ver].size();i++){
    		if(vis[g[ver][i]]==0){
    			partial+=dfs(g[ver][i]);
    		}
    	}
    	return 1+partial;
    }
    int main(){
    	generate();
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, m, u, v, curmax=-1;
    		scanf("%d %d", &n, &m);
    		for(int i=0;i<100005;i++){
    			g[i].clear();
    			vis[i]=0;
    		}
     
    		while(m--){
    			scanf("%d %d", &u, &v);
    			g[u].push_back(v);
    			g[v].push_back(u);
    		}
     
    		for(int i=1;i<=n;i++){
    			if(vis[i]==0){
    				curmax=max(curmax, dfs(i));
    			}
    		}
     
    		if(curmax==1){
    			printf("-1\n");
    			continue;
    		}
    		// curmax=min(curmax, n);
    		printf("%d\n", primes[curmax-1]);
    	}
    	return 0;
    } 
