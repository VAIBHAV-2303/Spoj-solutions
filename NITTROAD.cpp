    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int u;
    	int v;
    	int flag;
    }node;
    typedef struct Node1{
    	int par;
    	int count;
    	int height;
    }node1;
    node1 dsu[20005];
    node E[20005];
    stack<pair<char, int> > qs;
    stack<long long> ans;
    long long curr;
    int find(int ver){
    	if(dsu[ver].par==-1){
    		return ver;
    	}
    	return find(dsu[ver].par);
    } 
    void joincom(int u, int v){
    	int ru, rv;
    	ru=find(u);
    	rv=find(v);
     
    	curr-=(dsu[ru].count*dsu[rv].count);
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
    	int T;
    	scanf("%d", &T);
    	while(T--){
     
    		for(int i=0;i<20005;i++){
    			dsu[i].par=-1;
    			dsu[i].count=1;
    			dsu[i].height=0;
    		}
     
    		int n, q, r;
    		char ch;
    		scanf("%d", &n);
    		curr=(n*(n-1))/2;
     
    		for(int i=1;i<=n-1;i++){
    			scanf("%d %d", &E[i].u, &E[i].v);
    			E[i].flag=1;
    		}
     
    		scanf("%d", &q);
    		while(q--){
    			scanf("\n%c", &ch);
    			if(ch=='Q'){
    				qs.push(make_pair('Q', -1));
    			}
    			else{
    				scanf("%d", &r);
    				E[r].flag=0;
    				qs.push(make_pair('R', r));
    			}
    		}
     
    		for(int i=1;i<=n-1;i++){
    			if(E[i].flag==1){
    				joincom(E[i].u, E[i].v);
    			}
    		}
     
    		while(!qs.empty()){
    			if(qs.top().first=='Q'){
    				ans.push(curr);
    			}
    			else{
    				r=qs.top().second;
    				joincom(E[r].u, E[r].v);
    			}
    			qs.pop();
    		}
     
    		while(!ans.empty()){
    			printf("%lld\n", ans.top());
    			ans.pop();
    		}
    		printf("\n");
    	}
    	return 0;
    } 
