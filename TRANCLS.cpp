    #include<bits/stdc++.h>
    using namespace std;
    int adj[103][103];
    int main(){
        int T;
        scanf("%d", &T);
        for(int t=1;t<=T;t++){
     
            int n, u, v, curmin;
            scanf("%d", &n);
     
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    adj[i][j]=100000;
                }
            }
     
            for(int i=0;i<n;i++){
                scanf("%d %d", &u, &v);
                adj[u][v]=1;
            }
     
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        adj[j][k]=min(adj[j][k], adj[j][i]+adj[i][k]);
                    }
                }
            }
     
            int ans=0;
            for(int i=0;i<100;i++){
                for(int j=0;j<100;j++){
                    if(adj[i][j]!=100000){
                        if(adj[i][j]>1){
                            ans++;
                        }
                    }
                }
            }
            printf("Case #%d: %d\n", t, ans);
        }
        return 0;
    } 