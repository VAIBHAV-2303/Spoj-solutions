    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    pair<int, pair<int, int> > Q[200005];
    int a[300005];
    int last[1000006];
    int seg[1200005]={0};
    int ans[200005];
    int Search(int l, int r, int s, int e, int ind){
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
    		return Search(l, (s+e)/2, s, (s+e)/2, 2*ind) + Search((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1);
    	}
    }
    void update(int p, int s, int e, int ind, int pui){
    	if(s==e){
    		if(pui==1){
    			seg[ind]++;
    		}
    		else{
    			seg[ind]--;
    		}
    		ind=ind/2;
    		while(ind>=1){
    			seg[ind]=seg[2*ind]+seg[2*ind+1];
    			ind=ind/2;
    		}
    		return;
    	}
    	if(p>(s+e)/2){
    		return update(p, (s+e)/2+1, e, 2*ind+1, pui);
    	}
    	if(p<=(s+e)/2){
    		// printf("pui\n");
    		return update(p, s, (s+e)/2, 2*ind, pui);
    	}
    }
    int main(){
    	int n, q, l, r;
    	scanf("%d", &n);
     
    	for(int i=0;i<1000006;i++){
    		last[i]=-1;
    	}
     
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    	}
     
    	scanf("%d", &q);
     
    	for(int i=0;i<q;i++){
    		scanf("%d %d", &l, &r);
    		Q[i]=make_pair(r-1, make_pair(l-1, i));
    	}
     
    	sort(Q, Q+q);
    	// printf("pui\n");
    	int t=0;
    	for(int i=0;i<n;i++){
    		if(last[a[i]]!=-1){
    			update(last[a[i]], 0, n-1, 1, -1);
    		}
    		last[a[i]]=i;
    		update(i, 0, n-1, 1, 1);
    		while(Q[t].first<=i && t<q){
    			ans[Q[t].second.second]=Search(Q[t].second.first, Q[t].first, 0, n-1, 1);
    			t++;
    		}
    	}
     
    	for(int i=0;i<q;i++){
    		printf("%d\n", ans[i]);
    	}
     
    	return 0;
    } 
