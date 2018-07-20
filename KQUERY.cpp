    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<pair<long long, pair<char, int> > > arr;
    vector<pair <int, int> >query;
    int ans[200005];
    int seg[120009];
    int fn(int l, int r, int ind){
    	if(l==r){
    		return 1;
    	}
     
    	seg[2*ind]=fn(l, (l+r)/2, 2*ind);
    	seg[2*ind+1]=fn(((l+r)/2)+1, r, 2*ind+1);
     
    	return seg[2*ind]+seg[2*ind+1];
    }
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
    void update(int s, int e, int x, int ind){
    	if(s==e){
    		seg[ind]=0;
    		ind=ind/2;
    		while(ind!=0){
    			seg[ind]=seg[2*ind]+seg[2*ind+1];
    			ind=ind/2;
    		}
    		return;
    	}
    	if(x>(s+e)/2){
    		return update(((s+e)/2)+1, e, x, 2*ind+1);
    	}
    	else{
    		return update(s, (s+e)/2, x, 2*ind);
    	}
    }
    int main(){
    	int n, pui;
    	long long temp;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%lld", &temp);
    		arr.push_back(make_pair(temp, make_pair('a', i)));
    	}
     
    	seg[1]=fn(0, n-1, 1);
    	int q, l, r, t=0;
    	long long k;
    	scanf("%d", &q);
    	pui=q;
    	while(q--){
    		scanf("%d %d %lld", &l, &r, &k);
    		query.push_back(make_pair(l, r));
    		arr.push_back(make_pair(k, make_pair('q', t)));
    		t++;
    	}
     
    	sort(arr.begin(), arr.end());
     
    	for(int i=0;i<arr.size();i++){
    		if(arr[i].second.first=='a'){
    			update(0, n-1, arr[i].second.second, 1);
    			// printf("a %d\n", arr[i].second.second);
    			// for(int i=1;i<=9;i++){
    				// printf("%d ", seg[i]);
    			// }
    			// printf("\n");
    		}
    		else{
    			// printf("q %d %d\n", query[arr[i].second.second].first-1, query[arr[i].second.second].second-1);
    			ans[arr[i].second.second]=Search(query[arr[i].second.second].first-1, query[arr[i].second.second].second-1, 0, n-1, 1);
    		}
    	}
     
    	for(int i=0;i<pui;i++){
    		printf("%d\n", ans[i]);
    	}
     
    	return 0;
    } 
