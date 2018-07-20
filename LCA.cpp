    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int l;
    	int r;
    }node;
    node ind[1003];
    vector<pair<int, int> > a;
    vector<int> G[1003];
    pair<int, int> seg[100003];
     
    void dfs(int ver, int lev){
    	a.push_back(make_pair(lev, ver));
    	ind[ver].l=a.size()-1;
    	for(int i=0;i<G[ver].size();i++){
    		dfs(G[ver][i], lev+1);
    		a.push_back(make_pair(lev, ver));
    	}
    	a.push_back(make_pair(lev, ver));
    	ind[ver].r=a.size()-1;
    }
    pair<int, int> fn(int s, int e, int ind){
    	if(s==e){
    		return a[s];
    	}
    	seg[2*ind]=fn(s, (s+e)/2, 2*ind);
    	seg[2*ind+1]=fn((s+e)/2+1, e, 2*ind+1);
    	return min(seg[2*ind], seg[2*ind+1]);
    }
    pair<int, int> Search(int l, int r, int s, int e, int ind){
    	if(l<=s&&r>=e){
    		return seg[ind];
    	}
    	if(l>(s+e)/2){
    		return Search(l, r, (s+e)/2+1, e, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return Search(l, r, s, (s+e)/2, 2*ind);
    	}
    	else{
    		return min(Search(l, (s+e)/2, s, (s+e)/2, 2*ind), Search((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1));
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		a.clear();
    		for(int i=0;i<1003;i++){
    			G[i].clear();
    		}
     
    		int n, m, v, q;
    		scanf("%d", &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d", &m);
    			while(m--){
    				scanf("%d", &v);
    				G[i].push_back(v);
    			}
    		}
     
    		dfs(1, 0);
    		
    		/*for(int i=0;i<2*n;i++){
    			printf("%d %d\n", a[i].first, a[i].second);
    		}
    		for(int i=1;i<=n;i++){
    			printf("%d %d\n", ind[i].l, ind[i].r);
    		}*/
     
    		n=a.size();
    		seg[1]=fn(0, n-1, 1);
     
     
    		scanf("%d", &q);
    		int l, r;
    		printf("Case %d:\n", t);
    		while(q--){
    			scanf("%d %d", &l, &r);
    			if(min(ind[l].l, ind[r].l)==ind[l].l){
    				// printf("%d %d\n", ind[l].l, ind[r].l);
    				printf("%d\n", Search(ind[l].l, ind[r].l, 0, n-1, 1).second);
    			}
    			else{
    				// printf("%d %d\n", ind[r].l, ind[l].l);
    				printf("%d\n", Search(ind[r].l, ind[l].l, 0, n-1, 1).second);	
    			}
    		}
    	}
    	return 0;
    } 
