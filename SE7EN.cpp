    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[100005];
    int a[100005], b[100005], nop;
    long long val, z ,o;
    void dfs(int ver, int par){
        int count=0, pui=ver;
        while(pui!=0){
            if(pui%2==1){
                count++;
            }
            pui>>=1;
        }   
        count=count%2;
     
        if(count==0){
            a[ver]+=z;
        }
        else{
            a[ver]+=o;
        }
     
        if(a[ver]!=b[ver]){
            nop++;
            val+=(b[ver]-a[ver]);
            if(count==0){
                z+=(b[ver]-a[ver]);
            }
            else{
                o+=(b[ver]-a[ver]);
            }
        }
        for(int i=0;i<g[ver].size();i++){
            if(g[ver][i]!=par){
                dfs(g[ver][i], ver);
            }
        }
     
        if(count==0){
            z-=(b[ver]-a[ver]);
        }
        else{
            o-=(b[ver]-a[ver]);
        }
        a[ver]=b[ver];
     
    }
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            z=0, o=0, nop=0, val=0;
            for(int i=0;i<100005;i++){
                g[i].clear();
            }
            int n, u, v;
            scanf("%d", &n);
            for(int i=0;i<n-1;i++){
                scanf("%d %d", &u, &v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
     
            for(int i=1;i<=n;i++){
                scanf("%d", &a[i]);
            }
            for(int i=1;i<=n;i++){ 
                scanf("%d", &b[i]);
            }
     
            dfs(1, -1);
     
            printf("%d %lld\n", nop, val);
     
        }
        return 0;
    } 
