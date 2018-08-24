        #include<stdio.h>
        #include<bits/stdc++.h>
        using namespace std;
        int main(){
            vector<int> g[1003], pui;
            priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > q;
            int n, m, x;
            scanf("%d", &n);
            for(int i=0;i<n;i++){
                scanf("%d", &m);
                while(m--){
                    scanf("%d", &x);
                    g[i].push_back(x);
                }
            }
         
         
            for(int i=0;i<n;i++){
                q.push(g[i]);
            }
         
            while(!q.empty()){
                printf("%d ", q.top()[0]);
                pui=q.top();
                q.pop();
                if(pui.size()!=1){
                    pui.erase(pui.begin());
                    q.push(pui);
                }
            }
            printf("\n");
         
            return 0;
        }  
