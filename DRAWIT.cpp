    #include<bits/stdc++.h>
    #include<stdio.h>
    using namespace std;
    typedef struct Adj{
        int ver;
        int vis;
    }adj;
    vector<adj> G[105];
    int a[105];
    void dfs(int ver){
        for(int i=0;i<G[ver].size();i++){
            if(G[ver][i].vis==0){
                G[ver][i].vis=1;
                dfs(G[ver][i].ver);
            }
        }
    }
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            for(int i=0;i<105;i++){
            G[i].clear();
            }
            for(int i=0;i<105;i++){
                a[i]=0;
            }
            int n, dhui, temp, u, v, m;
            scanf("%d %d", &n, &m);
            adj chui;
            chui.vis=0;
            while(m--){
                scanf("%d %d %d", &u, &v, &temp);
                dhui=u;
                chui.ver=v;
                if(temp%2==0){
                    temp=2;
                }
                else{
                    temp=1;
                }
                for(int i=0;i<temp;i++){
                    a[u]++;
                    G[u].push_back(chui);
                }      
                chui.ver=u;
                for(int i=0;i<temp;i++){
                    a[v]++;
                    G[v].push_back(chui);
                }
            }
     
            int od=0, ev=0, st=-1, en=-1, flag=0, bleh=10000;
     
            for(int i=1;i<=n;i++){
                if(a[i]>0 && i<bleh && a[i]%2==0){
                    bleh=i;
                }
     
                if(a[i]%2==0){
                    ev++;
                }
                else{
                    od++;
                    if(od==1){
                        st=i;
                    }
                    else if(od==2){
                        en=i;
                    }
                    else if(od>=3){
                        flag=1;
                        break;
                    }
                }
            }
     
            if(flag || od==1){
                printf("NO\n");
                continue;
            }
     
            flag=0;
            if(od==2){
                chui.ver=st;
                G[en].push_back(chui);
            }
     
            if((od==0) || (od==2)){
                dfs(dhui);
                for(int i=0;i<=n;i++){
                    for(int j=0;j<G[i].size();j++){
                         if(G[i][j].vis==0){
                            printf("NO\n");	
                            flag=1;
                            break;
                        }
                    }
                    if(flag){
                        break;
                    }
                }
                if(flag==0){
                    if(od==0){
                        printf("YES 1\n");
                    }
                    else if(od==2){
                        printf("YES %d\n", min(st, en));
                    }
                }
            }       
            else{
                printf("NO\n");;
            }
     
        }
        return 0;
    }  
