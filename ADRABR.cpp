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
                    int n, m, u, v, pui, s, t;
                    node temp;
                    long long int weight;
                    scanf("%d %d %d %d", &n, &m, &s, &t);
                    while(m--){
                            scanf("%d %d %lld", &u, &v, &temp.weight);
                            temp.weight+=12;
                            temp.ver=v;
                            g[u].push_back(temp);
                            temp.ver=u;
                            g[v].push_back(temp);
                    }
     
                    for(int i=1;i<=n;i++){
                            ans[i]=1000000000000;
                    }
                    u=s;
                    v=t;
     
            //Initialization
                    pq.push(make_pair(0, u));
                    int newver;
     
                    while(!pq.empty()){
                            newver=pq.top().second;
                            // printf("%d %lld\n", newver, pq.top().first);
                            if(ans[newver]>pq.top().first){
                                    ans[newver]=pq.top().first;
                            }
                            pq.pop();
                            for(int i=0;i<g[newver].size();i++){
                                    if((ans[newver]+g[newver][i].weight)<ans[g[newver][i].ver]){
                                            pui=g[newver][i].ver;
                                            //printf("%d\n", tempspec.ver);
                                            weight=ans[newver]+g[newver][i].weight;
                                            pq.push(make_pair(weight, pui));
                                    }
                            }
                    }
    		// for(int i=1;i<=n;i++){
                            // printf("%lld\n", ans[i]);
                    // }
                    printf("%lld\n", ans[v]);
    	}
            return 0;
    } 
