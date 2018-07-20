    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	long long value;
    	long long lazy;
    }node;
    node seg[400005];
    void update(int s, int e, int l, int r, int ind, long long x){
    	if(seg[ind].lazy!=0){
    		seg[ind].value+=(e-s+1)*seg[ind].lazy;
    		if(2*ind<400005 && (2*ind+1)<400005){
    			seg[2*ind].lazy+=seg[ind].lazy;
    			seg[2*ind+1].lazy+=seg[ind].lazy;
    		}
    		seg[ind].lazy=0;
    	}
     
    	if(l>e){
    		return;
    	}
    	if(r<s){
    		return;
    	}
     
    	if(s>=l && e<=r){
    		seg[ind].value+=(e-s+1)*x;
    		if(2*ind<400005 && (2*ind+1)<400005){
    			seg[2*ind].lazy+=x;
    			seg[2*ind+1].lazy+=x;
    		}
    		int t=ind/2;
    		while(t!=0){
    			// printf("t->%d, %lld+%lld\n", t, seg[2*t].value, seg[2*t+1].value);
    			seg[t].value=seg[2*t].value+seg[2*t+1].value;
    			t=t/2;
    		}
    		return;
    	}
    	else if(l>(s+e)/2){
    		update(s, (s+e)/2, l, r, 2*ind, x);
    		update(((s+e)/2)+1, e, l, r, 2*ind+1, x);
    		return;
    	}
    	else if(r<=(s+e)/2){
    		update(((s+e)/2)+1, e, l, r, 2*ind+1, x);
    		update(s, (s+e)/2, l, r, 2*ind, x);
    		return;
    	}
    	else{
    		update(s, (s+e)/2, l, (s+e)/2, 2*ind, x);
    		update(((s+e)/2)+1, e, ((s+e)/2)+1, r, 2*ind+1, x);
    		return;
    	}
     
    }
    long long search(int s, int e, int l, int r, int ind){
    	if(seg[ind].lazy!=0){
    		seg[ind].value+=(e-s+1)*seg[ind].lazy;
    		if(2*ind<400005 && 2*ind+1<400005){
    			seg[2*ind].lazy+=seg[ind].lazy;
    			seg[2*ind+1].lazy+=seg[ind].lazy;
    		}
    		seg[ind].lazy=0;
    	}
     
    	if(l<=s&&r>=e){
    		return seg[ind].value;
    	}
    	if(l>(s+e)/2){
    		return search(((s+e)/2)+1, e, l, r, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return search(s, (s+e)/2, l, r, 2*ind);
    	}
    	else{
    		return search(s, (s+e)/2, l, (s+e)/2, 2*ind)+search(((s+e)/2)+1, e, ((s+e)/2)+1, r, 2*ind+1);
    	}
     
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
     
    		for(int i=0;i<400005;i++){
    			seg[i].value=0;
    			seg[i].lazy=0;
    		}
     
    		int n, q, ch, l, r;
    		long long x;
    		scanf("%d %d", &n, &q);
     
    		while(q--){
    			scanf("%d", &ch);
    			if(ch==0){
    				scanf("%d %d %lld", &l, &r, &x);
    				update(0, n-1, l-1, r-1, 1, x);
    			}
    			else{
    				scanf("%d %d", &l, &r);
    				printf("%lld\n", search(0, n-1, l-1, r-1, 1));
    			}
    			// for(int i=1;i<=15;i++){
    				// printf("%d->%lld,%lld  ", i, seg[i].value, seg[i].lazy);
    			// }
    			// printf("\n");
    		}
     
    	}
    	return 0;
    } 
