    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    pair <int, int> a[100005];
    int maxseg[400005], minseg[400005], b[100005];
    int maxfn(int l, int r, int ind){
    	if(l==r){
    		return a[l].second;
    	}
    	maxseg[2*ind]=maxfn(l, (l+r)/2, 2*ind);
    	maxseg[2*ind+1]=maxfn(((l+r)/2)+1, r, 2*ind+1);
    	return max(maxseg[2*ind], maxseg[2*ind+1]);
    }
    int minfn(int l, int r, int ind){
    	if(l==r){
    		return a[l].second;
    	}
    	minseg[2*ind]=minfn(l, (l+r)/2, 2*ind);
    	minseg[2*ind+1]=minfn(((l+r)/2)+1, r, 2*ind+1);
    	return min(minseg[2*ind], minseg[2*ind+1]);
    }
    int maxSearch(int l, int r, int s, int e, int ind){
    	if(l<=s&&r>=e){
    		return maxseg[ind];
    	}
    	if(l>(s+e)/2){
    		return maxSearch(l, r, (s+e)/2+1, e, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return maxSearch(l, r, s, (s+e)/2, 2*ind);
    	}
    	else{
    		return max(maxSearch(l, (s+e)/2, s, (s+e)/2, 2*ind), maxSearch((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1));
    	}
    }
    int minSearch(int l, int r, int s, int e, int ind){
    	if(l<=s&&r>=e){
    		return minseg[ind];
    	}
    	if(l>(s+e)/2){
    		return minSearch(l, r, (s+e)/2+1, e, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return minSearch(l, r, s, (s+e)/2, 2*ind);
    	}
    	else{
    		return min(minSearch(l, (s+e)/2, s, (s+e)/2, 2*ind), minSearch((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1));
    	}
    }
    int bs(int l, int r, int x){
    	if(l==r){
    		return l;
    	}
    	if(r-l==1){
    		if(a[l].first==x){
    			return l;
    		}
    		return r;
    	}
    	int mid=(l+r)/2;
    	if(a[mid].first>=x){
    		return bs(l, mid, x);
    	}
    	else{
    		return bs(mid+1, r, x);
    	}
    }
    int main(){
    	int n, u, num, l, lower, upper;
    	long long ans, x;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i].first);
    		b[i]=a[i].first;
    		a[i].second=i;
    	}
     
    	sort(a, a+n);
    	// for(int i=0;i<n;i++){
    		// printf("%d ", a[i].second);
    	// }
    	// printf("\n");
    	maxseg[1]=maxfn(0, n-1, 1);
    	minseg[1]=minfn(0, n-1, 1);
     
    	while(1){
    		scanf("%d %lld", &u, &x);
    		if(u==0 && x==0){
    			return 0;
    		}
    		u--;
    		num=b[u];
    		l=bs(0, n-1, num);
    		// printf("%d\n", l);
    		lower=minSearch(l, n-1, 0, n-1, 1);
    		upper=maxSearch(l, n-1, 0, n-1, 1);
    		ans=1LL*num*max(u-lower, upper-u);
    		if(ans>x){
    			printf("%lld\n", ans-x);
    		}
    		else if(ans==x){
    			printf("Maximum\n");
    		}
    		else{
    			printf("Not possible\n");
    		}
    	}
    } 
