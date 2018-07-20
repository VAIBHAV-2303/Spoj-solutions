    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> g[10005];
    int ans[10005]={0};
    int heightarr[10005]={0};
    int height(int ver, int par){
    	if(heightarr[ver]==-1){
    		int max=-1, ansind, max1=-1;
    		for(int i=0;i<g[ver].size();i++){
    			if(g[ver][i]!=par && height(g[ver][i], ver)>max){
    				ansind=i;
    				max=height(g[ver][i], ver);
    			}
    		}
     
    		for(int i=0;i<g[ver].size();i++){
    			if(g[ver][i]!=par && height(g[ver][i], ver)>max1 && i!=ansind){
    				max1=height(g[ver][i], ver);
    			}
    		}
     
     
    		ans[ver]=max+max1+2;
    		
    		heightarr[ver]=max+1;
    	}
    	return heightarr[ver];
    }
    int main(){
    	int n, u, v, fans=-1;
    	scanf("%d", &n);
     
    	for(int i=1;i<=n;i++){
    		heightarr[i]=-1;
    	}
     
    	for(int i=0;i<n-1;i++){
    		scanf("%d %d", &u, &v);
    		g[u].push_back(v);
    		g[v].push_back(u);
    	}
     
    	int blaeh=height(1, -1);
     
    	for(int i=1;i<=n;i++){
    		if(ans[i]>fans){
    			fans=ans[i];
    		}
    	}
     
    	printf("%d\n", fans);
     
    	return 0;
    } 
