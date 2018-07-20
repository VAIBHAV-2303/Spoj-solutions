    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> G[100005];
    vector<int> tot;
    int ind[100005], n1, n2;
    int curmax;
    void dfs(int ver, int prev, int len){
    	if(G[ver].size()==0){
    		if((prev==1 && ver>n1) || (prev==2 && ver<=n1)){
    			if(len+1>curmax){
    				tot.clear();
    				tot.push_back(ver);
    				curmax=len+1;
    			}
    			else if(len+1==curmax){
    				tot.push_back(ver);
    			}
    		}
    		else{
    			if(len>curmax){
    				tot.clear();
    				tot.push_back(ver);
    				curmax=len;
    			}
    			else if(len==curmax){
    				tot.push_back(ver);
    			}
    		}
    		return;
    	}
     
    	for(int i=0;i<G[ver].size();i++){
    		if(prev==1 && ver>n1){
    			dfs(G[ver][i], 2, len+1);
    		}
    		else if(prev==2 && ver<=n1){
    			dfs(G[ver][i], 1, len+1);
    		}
    		else{
    			dfs(G[ver][i], prev, len);
    		}
    	}
     
    }
    int main(){
    	while(1){
     
    		for(int i=0;i<100005;i++){
    			G[i].clear();
    			ind[i]=0;
    		}
    		curmax=0;
    		tot.clear();
    		int d, u, v;
    		scanf("%d %d %d", &n1, &n2, &d);
    		if(n1==0 && n2==0 && d==0){
    			break;
    		}
    		while(d--){
    			scanf("%d %d", &u, &v);
    			G[v].push_back(u);
    			ind[u]++;
    		}
     
    		for(int i=1;i<=n1+n2;i++){
    			if(ind[i]==0){
    				if(i<=n1){
    					dfs(i, 2, 0);
    				}
    				else{
    					dfs(i, 1, 0);
    				}
    			}
    		}
     
    		sort(tot.begin(), tot.end());
     
    		if(tot[0]>n1){
    			printf("%d\n", max(3, curmax+1));
    		}
    		else if(tot[tot.size()-1]<=n1){
    			printf("%d\n", max(3, curmax+1));
    		}
    		else{
    			printf("%d\n", max(3, curmax+2));
    		}
     
    	}
    	return 0;
    } 
