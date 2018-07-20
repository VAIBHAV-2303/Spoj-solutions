    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int ver;
    	long long weight;
    }node;
    long long ans[105];
    vector<node> g[105];
    #define pli pair<long long int, int>
    priority_queue< pli, vector<pli>, greater<pli> > pq;
    int main(){
    	int n, s, T, m, u;
    	long long w;
    	node temp;
    	scanf("%d %d %d %d", &n, &s, &T, &m);
    	while(m--){
    		scanf("%d %d %lld", &temp.ver, &u, &temp.weight);
    		g[u].push_back(temp);
    	}
     
    	for(int i=0;i<105;i++){
    		ans[i]=10000000000000000;
    	}
     
    	ans[s]=0;
     
    	int newver, pui;
    	pq.push(make_pair(0, s));
    	while(!pq.empty()){
    		newver=pq.top().second;
    		if(ans[newver]>pq.top().first){
    			ans[newver]=pq.top().first;
    		}
    		pq.pop();
    		for(int i=0;i<g[newver].size();i++){
    			if((ans[newver]+g[newver][i].weight)<ans[g[newver][i].ver]){
    				pui=g[newver][i].ver;
    				w=ans[newver]+g[newver][i].weight;
    				pq.push(make_pair(w, pui));
    			}
    		}
    	}
    	int fans=0;
    	for(int i=1;i<=n;i++){
    		if(ans[i]<=T){
    			fans++;
    		}
    	}
     
    	printf("%d\n", fans);
     
    	return 0;
    } 
