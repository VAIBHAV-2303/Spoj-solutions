    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    char a[1005][1005];
    int vis[1005][1005][9];
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
     
            int n, m;
            pair<int, int> s, f;
            scanf("%d %d", &n, &m);
     
            for(int i=0;i<n;i++){
                scanf("%s", a[i]);
            }
     
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(a[i][j]=='S'){
                        s=make_pair(i, j);
                    }
                    else if(a[i][j]=='F'){
                        f=make_pair(i, j);
                        for(int t=0;t<9;t++){
                            vis[i][j][t]=0;
                        }
                    }
                    else if(a[i][j]=='X'){
                        vis[i][j][0]=1;
                    }
                    else{
                        for(int t=0;t<9;t++){
                            vis[i][j][t]=0;
                        }
                    }
                }
            }
     
            queue<pair<int, pair<int, int> > > q;
            pair<int, pair<int, int> > temp;
            q.push(make_pair(0, make_pair(s.first, s.second)));
            int flag=0;
            while(!q.empty()){
                temp=q.front();
                for(int i=0;i<9;i++){
                    vis[temp.second.first][temp.second.second][i]=1;
                }
                q.pop();
                if(temp.second.first==f.first && temp.second.second==f.second){
                    printf("%d\n", temp.first);
                    flag=1;
                    break;
                }
                int i, j;
                
                i=temp.second.first-1;
                j=temp.second.second;
                while(i>=0){
                    if(vis[i][j][0]==1 || vis[i][j][1]==1){
                        break;
                    }
                    vis[i][j][1]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    i--;
                }
                
                i=temp.second.first+1;
                j=temp.second.second;
                while(i<n){
                    if(vis[i][j][0]==1 || vis[i][j][2]==1){
                        break;
                    }
                    vis[i][j][2]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    i++;
                }
     
                i=temp.second.first;
                j=temp.second.second-1;
                while(j>=0){
                    if(vis[i][j][0]==1 || vis[i][j][3]==1){
                        break;
                    }
                    vis[i][j][3]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    j--;
                }
     
                i=temp.second.first;
                j=temp.second.second+1;
                while(j<m){
                    if(vis[i][j][0]==1 || vis[i][j][4]==1){
                        break;
                    }
                    vis[i][j][4]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    j++;
                }
     
                i=temp.second.first-1;
                j=temp.second.second+1;
                while(i>=0 && j<m){
                    if(vis[i][j][0]==1 || vis[i][j][5]==1){
                        break;
                    }
                    vis[i][j][5]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    i--;
                    j++;
                }
     
                i=temp.second.first-1;
                j=temp.second.second-1;
                while(i>=0 && j>=0){
                    if(vis[i][j][0]==1 || vis[i][j][6]==1){
                        break;
                    }
                    vis[i][j][6]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    i--;
                    j--;
                }
     
                i=temp.second.first+1;
                j=temp.second.second-1;
                while(i<n && j>=0){
                    if(vis[i][j][0]==1 || vis[i][j][7]==1){
                        break;
                    }
                    vis[i][j][7]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    i++;
                    j--;
                }
     
                i=temp.second.first+1;
                j=temp.second.second+1;
                while(i<n && j<m){
                    if(vis[i][j][0]==1 || vis[i][j][8]==1){
                        break;
                    }
                    vis[i][j][8]=1;
                    q.push(make_pair(temp.first+1, make_pair(i, j)));
                    i++;
                    j++;
                }
     
            }
            if(flag==0){
                printf("-1\n");
            }
        }
        return 0;
    } 
