    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int par;
    	int height;
    	int count;
    }node;
    vector<pair<int, pair<int, int> > >E;
    vector<pair<int, pair<int, int> > > Q;
    node dsu[100005];
    int ans[300005];
    int find(int v){
    	if(dsu[v].par==-1){
    		return v;
    	}
    	return find(dsu[v].par);
    }
    void join(int u, int v){
    	int ru, rv;
    	ru=find(u);
    	rv=find(v);
     
    	if(ru==rv){
    		return;
    	}
     
    	if(dsu[ru].height>dsu[rv].height){
    		dsu[rv].par=ru;
    		dsu[ru].count+=dsu[rv].count;
    	}
    	else if(dsu[rv].height>dsu[ru].height){
    		dsu[ru].par=rv;
    		dsu[rv].count+=dsu[ru].count;
    	}
    	else{
    		dsu[rv].par=ru;
    		dsu[ru].count+=dsu[rv].count;
    		dsu[ru].height++;
    	}
     
    }
    int main(){
     
    	for(int i=0;i<100005;i++){
    		ans[i]=0;
    		dsu[i].par=-1;
    		dsu[i].count=1;
    		dsu[i].height=0;
    	}
     
    	int n, m, q, u, v, w;
    	scanf("%d %d %d", &n, &m, &q);
    	while(m--){
    		scanf("%d %d %d", &u, &v, &w);
    		E.push_back(make_pair(w, make_pair(u, v)));
    	}
     
    	sort(E.begin(), E.end(), greater<pair<int, pair<int, int> > >() );
    	
    	for(int i=0;i<q;i++){
    		scanf("%d %d", &v, &w);
    		Q.push_back(make_pair(w, make_pair(v, i)));
    	}
     
    	sort(Q.begin(), Q.end(), greater<pair<int, pair<int, int> > >() );
    	int j=0;
    	for(int i=0;i<q;i++){
    		w=Q[i].first;
    		while(E[j].first>=w){
    			join(E[j].second.first, E[j].second.second);
    			j++;
    		}
    		ans[Q[i].second.second]=dsu[find(Q[i].second.first)].count;
    	}
     
    	for(int i=0;i<q;i++){
    		printf("%d\n", ans[i]);
    	}
     
    	return 0;
    } 
