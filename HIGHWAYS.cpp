    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
            int ver;
            long long weight;
    }node;
    long long ans[100005];
    #define pli pair<long long int, int>
    priority_queue< pli, vector<pli>, greater<pli> > pq;
    int main(){
            int T;
            scanf("%d", &T);
            while(T--){
    		vector<node> g[100005];
                    int n, m, u, v, pui, s, e;
                    node temp;
                    scanf("%d %d %d %d", &n, &m, &s, &e);
                    while(m--){
                            scanf("%d %d %lld", &u, &v, &temp.weight);
                            temp.ver=v;
                            g[u].push_back(temp);
                            temp.ver=u;
                            g[v].push_back(temp);
                    }
                    for(int i=1;i<=n;i++){
                            ans[i]=10000000000;
                    }
     
                    ans[s]=0;
                    pq.push(make_pair(0, s));
                    int newver;
                    while(!pq.empty()){
                            newver=pq.top().second;
                            pq.pop();
                            for(int i=0;i<g[newver].size();i++){
                                    if((ans[newver]+g[newver][i].weight)<ans[g[newver][i].ver]){
                                            pui=g[newver][i].ver;
                                            ans[pui]=ans[newver]+g[newver][i].weight;
                                            pq.push(make_pair(ans[pui], pui));
                                    }
                            }
                    }
    		if(ans[e]==10000000000){
    			printf("NONE\n");
    			continue;
    		}
                    printf("%lld\n", ans[e]);
    	}
            return 0;
    }
     
