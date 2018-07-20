        #include<stdio.h>
        #include<bits/stdc++.h>
        using namespace std;
        vector<int> g[150005], gd[150005], topsort, scc[150005], sccd[150005];
        int vis[150005]={0}, outd[150005]={0}, which[150005]={0}, ind[150005]={0}, temp[150005]={0};
        set<pair<int, int> > lset, rset;
        set<int> anscomp;
        stack<int> st;
        queue<int> q;
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
                    ind[which[g[ver][i]]]++;
                    temp[which[g[ver][i]]]++;
                    scc[which[ver]].push_back(which[g[ver][i]]);
                    sccd[which[g[ver][i]]].push_back(which[ver]);
                }
                if(vis[g[ver][i]]==0){
                    final(g[ver][i]);
                }
            }
        }
        int main(){
            int n, m, u, v, x;
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
     
            // for(int i=1;i<=n;i++){
                // printf("%d %d\n", i, which[i]);
            // }
         
        // answer
            t--;
            for(int i=1;i<=t;i++){
                // printf("%d %d\n", ind[i], i);
                rset.insert(make_pair(ind[i], i));
                if(ind[i]==0){
                    // printf("%d\n", i);
                    q.push(i);
                }
            }
     
            while(!q.empty()){
                x=q.front();
                q.pop();
                for(int i=0;i<scc[x].size();i++){
                    temp[scc[x][i]]--;
                    if(temp[scc[x][i]]==0){
                        q.push(scc[x][i]);
                    }
                }
                // printf("%d\n", x);
                topsort.push_back(x);
            }
     
            set<pair<int, int> >:: iterator it;
            it=rset.find(make_pair(ind[topsort[0]], topsort[0]));
            rset.erase(it);
     
            for(int i=0;i<t;i++){
                int flag=0;
                // printf("%d\n", topsort[i]);
                if(!lset.empty()){
                    it=lset.begin();
                    if((*it).first == 0){
                        // printf("pui\n");   
                        flag=1;
                    }
                }
                if(!rset.empty()){
                    it=rset.begin();
                    if((*it).first==0){
                        // printf("chui\n");
                        flag=1;
                    }
                }
                if(flag==0){
                    // printf("pui\n");
                    anscomp.insert(topsort[i]);
                }
     
                for(int j=0;j<scc[topsort[i]].size();j++){
                    it=rset.find(make_pair(ind[scc[topsort[i]][j]], scc[topsort[i]][j]));
                    if(it!=rset.end()){
                        rset.erase(it);
                    }
                    ind[scc[topsort[i]][j]]--;
                    // printf("%d %d\n", ind[scc[topsort[i]][j]], scc[topsort[i]][j]);
                    rset.insert(make_pair(ind[scc[topsort[i]][j]], scc[topsort[i]][j]));
                }
                lset.insert(make_pair(0, topsort[i]));
                if(i+1<t){
                    it=rset.find(make_pair(ind[topsort[i+1]], topsort[i+1]));
                    rset.erase(it);
                    for(int j=0;j<sccd[topsort[i+1]].size();j++){
                        it=lset.find(make_pair(outd[sccd[topsort[i+1]][j]], sccd[topsort[i+1]][j]));
                        if(it!=lset.end()){
                            lset.erase(it);
                        }
                        outd[sccd[topsort[i+1]][j]]++;
                        lset.insert(make_pair(outd[sccd[topsort[i+1]][j]], sccd[topsort[i+1]][j]));
                    }
                }   
            }
            
            set<int>::iterator iter;
            for(int i=1;i<=n;i++){
                iter=anscomp.find(which[i]);
                if(iter!=anscomp.end()){
                    q.push(i);
                }
            }
            printf("%lu\n", q.size());
     
            while(!q.empty()){
                printf("%d ", q.front());
                q.pop();
            }
            printf("\n");
            return 0;
        }  
