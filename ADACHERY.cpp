    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<pair<int, int> > E;
    long long int deg[100005]={0};
    bitset<100005> G[100005];
    int main(){
    	int n, m, u, v;
    	scanf("%d %d", &n, &m);
    	while(m--){
    		scanf("%d %d", &u, &v);
    		deg[u]++;
    		deg[v]++;
    		E.push_back(make_pair(u, v));
    		G[u][v]=1;
    		G[v][u]=1;
    	}	
    	long long ans=0;
    	for(int i=0;i<n;i++){
    		ans+=((deg[i])*(deg[i]-1))/2;
    	}
     
    	for(int i=0;i<E.size();i++){
    		ans-=(G[E[i].first] & G[E[i].second]).count();
    	}
    	printf("%lld\n", ans);
     
    	return 0;
    } 
