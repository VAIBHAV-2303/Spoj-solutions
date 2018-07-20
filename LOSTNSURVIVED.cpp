#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	int par;
	int height;
	int count;
}node;
node dsu[100005];
multiset<int> S;
multiset<int>:: iterator it;
int findp(int v){
	if(dsu[v].par==-1){
		return v; 
	}	
	return findp(dsu[v].par);
}
void join(int u, int v){
	int ru, rv;
	ru=findp(u);
	rv=findp(v);
 
	if(ru==rv){
		return;
	}
 
	it=S.find(dsu[ru].count);
	S.erase(it);
	it=S.find(dsu[rv].count);
	S.erase(it);
	S.insert(dsu[ru].count+dsu[rv].count);
 
	if(dsu[ru].height>dsu[rv].height){
		dsu[ru].count+=dsu[rv].count;
		dsu[rv].par=ru;
	}
	else if(dsu[ru].height<dsu[rv].height){
		dsu[rv].count+=dsu[ru].count;
		dsu[ru].par=rv;
	}
	else{
		dsu[ru].count+=dsu[rv].count;
		dsu[rv].par=ru;
		dsu[ru].height++;
	}
}
int main(){
	int n, q, u, v, b, s;
	scanf("%d %d", &n, &q);
 
	for(int i=1;i<=n;i++){
		dsu[i].count=1;
		dsu[i].height=0;
		dsu[i].par=-1;
		S.insert(1);
	}
 
	while(q--){
		scanf("%d %d", &u, &v);
		join(u, v);
		printf("%d\n", (*S.rbegin()) - (*S.begin()));
	}
 
	return 0;
} 
