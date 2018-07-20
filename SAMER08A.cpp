    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    #define pli pair<long long int, int>
    #define newpli pair<long long int, pair<int, int> >
    priority_queue< newpli, vector<newpli>, greater<newpli> > pq;
    long long ans[505];
    vector<int> path[505];
    vector<pli> g[505];
    set<pair<int, int> > S;
    void fn(int x){
    	for(int i=0;i<path[x].size();i++){
    		S.insert(make_pair(path[x][i], x));
    		fn(path[x][i]);
    	}
    }
    int main(){
    	while(1){
    		int n, m, s, d, u, v;
    		long long weight;
    		for(int i=0;i<505;i++){
    			g[i].clear();
    			path[i].clear();
    		}
    		S.clear();
    		for(int i=0;i<505;i++){
    			ans[i]=1000000000000000;
    		}
     
    		scanf("%d %d", &n, &m);
    		if(n==0 && m==0){
    			break;
    		}
    		scanf("%d %d", &s, &d);
     
    		while(m--){
    			scanf("%d %d %lld", &u, &v, &weight);
    			g[u].push_back(make_pair(weight, v));
    		}
     
    		newpli temp;
    		pq.push(make_pair(0, make_pair(s, -1)));
    		while(!pq.empty()){
    			temp=pq.top();
    			pq.pop();
    			if(ans[temp.second.first]>=temp.first){
    				ans[temp.second.first]=temp.first;
    				path[temp.second.first].push_back(temp.second.second);
    			}
    			for(int i=0;i<g[temp.second.first].size();i++){
    				if(ans[temp.second.first]+g[temp.second.first][i].first<ans[g[temp.second.first][i].second]){
    					pq.push(make_pair(ans[temp.second.first]+g[temp.second.first][i].first, make_pair(g[temp.second.first][i].second, temp.second.first)));
    				}
    			}
    		}
    		if(path[d].empty()){
    			printf("-1\n");
    			continue;
    		}
     
    		fn(d);
     
    		set<pair <int, int> >:: iterator it;
     
    		for(int i=0;i<505;i++){
    			ans[i]=1000000000000000;
    			path[i].clear();
    		}
     
    		pq.push(make_pair(0, make_pair(s, -1)));
    		while(!pq.empty()){
    			temp=pq.top();
    			pq.pop();
    			if(ans[temp.second.first]>temp.first){
    				ans[temp.second.first]=temp.first;
    				path[temp.second.first].push_back(temp.second.second);
    			}
    			for(int i=0;i<g[temp.second.first].size();i++){
    				it=S.find(make_pair(temp.second.first, g[temp.second.first][i].second));
    				if(ans[temp.second.first]+g[temp.second.first][i].first<ans[g[temp.second.first][i].second] && it==S.end()){
    					pq.push(make_pair(ans[temp.second.first]+g[temp.second.first][i].first, make_pair(g[temp.second.first][i].second, temp.second.first)));
    				}
    			}
    		}
     
    		if(path[d].empty()){
    			printf("-1\n");
    		}
    		else{
    			printf("%lld\n", ans[d]);
    		}
    	}
    	return 0;
    } 
