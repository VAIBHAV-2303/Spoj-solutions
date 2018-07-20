    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long int arr[300005];
    vector<long long int> seg[1200009];
    void merge(int a, int b, int ind){
    	int i=0, j=0;
    	while(i<seg[a].size() && j<seg[b].size()){
    		if(seg[a][i]<seg[b][j]){
    			seg[ind].push_back(seg[a][i]);
    			i++;
    		}		
    		else{
    			seg[ind].push_back(seg[b][j]);
    			j++;
    		}
    	}
    	while(i<seg[a].size()){
    		seg[ind].push_back(seg[a][i]);
    		i++;
    	}
    	while(j<seg[b].size()){
    		seg[ind].push_back(seg[b][j]);
    		j++;	
    	}
    }
    int fnc(int l, int r, int par, int child){
    	if(child==0){
    		if(seg[2*par].size()!=0){
    			return 2*par;
    		}
    		else{
    			if(r==l){
    				seg[2*par].push_back(arr[r]);
    				return 2*par;
    			}
    			merge(fnc(l, (r+l)/2, 2*par, 0), fnc((r+l)/2+1, r, 2*par, 1), 2*par);
    			return 2*par;
    		}
    	}
    	else{
    		if(seg[2*par+1].size()!=0){
    			return 2*par+1;
    		}
    		else{
    			if(r==l){
    				seg[2*par+1].push_back(arr[r]);
    				return 2*par+1;
    			}
    			merge(fnc(l, (r+l)/2, 2*par+1, 0), fnc((r+l)/2+1, r, 2*par+1, 1), 2*par+1);
    			return 2*par+1;
    		}
    	}
    }
    long long bs(int ind, long long x){
    	int l=0, r=seg[ind].size(), mid;
    	r--;
     
    	while(r>=l){
    		mid=(l+r)/2;
    		if(l==r){
    			return seg[ind][l];
    		}
     
    		if((r-l)==1){
    			if(seg[ind][r]<=x){
    				return seg[ind][r];
    			}
    			else{
    				return seg[ind][l];
    			}
    		}
     
    		if(seg[ind][mid]>x){
    			r=mid-1;
    		}
    		else{
    			l=mid;
    		}
    	}
    }
    int Search(int l, int r, int s, int e, int ind, long long x){
    	if(l<=s&&r>=e){
    		if(seg[ind][0]>x){
    			return 0;
    		}
    		return bs(ind, x);
    	}
    	if(l>(s+e)/2){
    		return Search(l, r, (s+e)/2+1, e, 2*ind+1, x);
    	}
    	if(r<=(s+e)/2){
    		return Search(l, r, s, (s+e)/2, 2*ind, x);
    	}
    	else{
    		return max(Search(l, (s+e)/2, s, (s+e)/2, 2*ind, x), Search((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1, x));
    	}
    }
    int main(){
    	int n, q;
    	scanf("%d %d", &n, &q);
    	for(int i=0;i<n;i++){
    		scanf("%lld", &arr[i]);
    	}
    	merge(fnc(0, (n-1)/2, 1, 0), fnc((n+1)/2, n-1, 1, 1), 1);
     
    	int l, r;
    	long long x;
    	while(q--){
    		scanf("%d %d %lld", &l, &r, &x);
    		printf("%d\n", Search(l, r, 0, n-1, 1, x));
    	}
    	return 0;
    } 
