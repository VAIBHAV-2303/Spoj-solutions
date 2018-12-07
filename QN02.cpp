    #include<bits/stdc++.h>
    using namespace std;
    pair<int, int> par[100005];
     
    pair<int, int> find(int v){
    	if(par[v].first==v){
    		return par[v];
    	}
    	return find(par[v].first);
    }
    int main(){
     
    	for(int i=0;i<100005;i++){
    		par[i].first=i;
    		par[i].second=0;
    	}
     
    	int n, m, q, u, v;
    	pair<int, int> ru, rv;
    	scanf("%d %d", &n, &m);
     
    	while(m--){
    		scanf("%d %d", &u, &v);
    		ru=find(u);
    		rv=find(v);
    		if(ru.first!=rv.first){
    			if(ru.second>rv.second){
    				par[rv.first].first=ru.first;
    			}
    			else if(rv.second>ru.second){
    				par[ru.first].first=rv.first;
    			}
    			else{
    				par[rv.first].first=ru.first;
    				par[ru.first].second++;
    			}
    		}
    	}
     
    	scanf("%d", &q);
     
    	while(q--){
    		scanf("%d %d", &u, &v);
    		ru=find(u);
    		rv=find(v);
    		// printf("%d %d\n", ru.first, rv.first);
    		if(ru.first==rv.first){
    			printf("YES\n");
    		}
    		else{
    			printf("NO\n");
    		}
    	}
    	return 0;
    } 