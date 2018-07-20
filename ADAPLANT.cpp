    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	long long maxx;
    	long long minn;
    }node;
    node seg[400005];
    long long a[100005];
    node fn(int l, int r, int ind){
    	node temp;
    	if(l==r){
    		temp.maxx=a[l];
    		temp.minn=a[l];
    		return temp;
    	}
    	seg[2*ind]=fn(l, (l+r)/2, 2*ind);
    	seg[2*ind+1]=fn(((l+r)/2)+1, r, 2*ind+1);
    	temp.maxx=max(seg[2*ind].maxx, seg[2*ind+1].maxx);
    	temp.minn=min(seg[2*ind].minn, seg[2*ind+1].minn);
    	return temp;
    }
    long long Searchx(int l, int r, int s, int e, int ind){
    	if(l<=s&&r>=e){
    		return seg[ind].maxx;
    	}
    	if(l>(s+e)/2){
    		return Searchx(l, r, (s+e)/2+1, e, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return Searchx(l, r, s, (s+e)/2, 2*ind);
    	}
    	else{
    		return max(Searchx(l, (s+e)/2, s, (s+e)/2, 2*ind), Searchx((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1));
    	}
    }
    long long Searchn(int l, int r, int s, int e, int ind){
    	if(l<=s&&r>=e){
    		return seg[ind].minn;
    	}
    	if(l>(s+e)/2){
    		return Searchn(l, r, (s+e)/2+1, e, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return Searchn(l, r, s, (s+e)/2, 2*ind);
    	}
    	else{
    		return min(Searchn(l, (s+e)/2, s, (s+e)/2, 2*ind), Searchn((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1));
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, k;
    		scanf("%d %d", &n, &k);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &a[i]);
    		}
    		seg[1]=fn(0, n-1, 1);
    		long long currmax=-1;
    		if(k>n-2){
    			printf("%lld\n", Searchx(0, n-1, 0, n-1, 1)-Searchn(0, n-1, 0, n-1, 1));
    			continue;
    		}
    		for(int i=k+1;i<n;i++){
    			if(Searchx(i-k-1, i, 0, n-1, 1)-Searchn(i-k-1, i, 0, n-1, 1)>currmax){
    				currmax=Searchx(i-k-1, i, 0, n-1, 1)-Searchn(i-k-1, i, 0, n-1, 1);
    			}
    		}
    		printf("%lld\n", currmax);
    	}
    	return 0;
    }
     
