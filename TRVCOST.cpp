    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long ans[600];
    #define pli pair<long long int, int>
    priority_queue< pli, vector<pli>, greater<pli> > pq;
    int main(){
              long long int g[505][505];
              for(int i=0;i<505;i++){
                    for(int j=0;j<505;j++){
                            g[i][j]=1000000000000;
                    }
              }
              int m, u, v;
              long long int weight;
              scanf("%d", &m);
              while(m--){
                    scanf("%d %d %lld", &u, &v, &weight);
                    g[u][v]=min(g[u][v], weight);
                    g[v][u]=min(g[v][u], weight);
            }
            scanf("%d", &u);
     
            for(int i=0;i<600;i++){
                    ans[i]=10000000000;
            }
     
            pq.push(make_pair(0, u));
            ans[u]=0;
            int newver;
            while(!pq.empty()){
                    newver=pq.top().second;
                    pq.pop();
                    for(int i=0;i<505;i++){
                            if((ans[newver]+g[newver][i])<ans[i]){
                                    ans[i]=ans[newver]+g[newver][i];
                                    pq.push(make_pair(ans[i], i));
                            }
                    }
            }
            int q;
            scanf("%d", &q);
            while(q--){
                    scanf("%d", &v);
                    if(ans[v]==10000000000){
                            printf("NO PATH\n");
                    }
                    else{
                            printf("%lld\n", ans[v]);
                    }
            }
            return 0;
    } 
