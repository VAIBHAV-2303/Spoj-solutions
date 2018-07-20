    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    char G[101][101];
    int vis[101][101];
    int r, c, flag;
    char aiw[10]={'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
    void dfs(int i, int j, int ind){
    	if(ind==10){
    		flag=1;
    		return;
    	}
    	if(i<0 || i>=r || j<0 || j>=c || vis[i][j]==1){
    		return;
    	}
     
    	if(G[i][j]==aiw[ind]){
    		vis[i][j]=1;
    		dfs(i+1, j, ind+1);
    		dfs(i-1, j, ind+1);
    		dfs(i, j+1, ind+1);
    		dfs(i, j-1, ind+1);
    		dfs(i+1, j+1, ind+1);
    		dfs(i-1, j-1, ind+1);
    		dfs(i+1, j-1, ind+1);
    		dfs(i-1, j+1, ind+1);
    		vis[i][j]=0;
    	}
     
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		flag=0;
    		scanf("%d %d", &r, &c);
    		for(int i=0;i<r;i++){
    			scanf("%s", G[i]);
    		}
     
    		for(int i=0;i<101;i++){
    			for(int j=0;j<101;j++){
    				vis[i][j]=0;
    			}
    		}
     
    		for(int i=0;i<r;i++){
    			for(int j=0;j<c;j++){
    				if(G[i][j]=='A'){
    					vis[i][j]=1;
    					dfs(i+1, j, 1);
    					dfs(i-1, j, 1);
    					dfs(i, j+1, 1);
    					dfs(i, j-1, 1);
    					dfs(i+1, j+1, 1);
    					dfs(i-1, j-1, 1);
    					dfs(i+1, j-1, 1);
    					dfs(i-1, j+1, 1);
    					vis[i][j]=0;
    				}
    			}
    		}
     
    		if(flag){
    			printf("YES\n");
    		}
    		else{
    			printf("NO\n");
    		}
    	}
    	return 0;
    } 
