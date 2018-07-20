    #include <stdio.h>
     
    using namespace std;
     
    typedef struct node{
    	long long int sum;
    	long long int pre;
    	long long int suf;
    	long long int ans;
    }node;
     
    long long int arr[100002];
    node seg[400002];
     
    long long int maxx (long long int a, long long int b) { return (a >= b) ? a : b; }
     
    void make (int l, int r, int cur)
    {
    	if (l == r)
    	{
    		node t;
    		t.pre = t.suf = t.ans = t.sum = arr[l];
    		seg[cur] = t;
    		return;
    	}
    	make(l,l+(r-l)/2,2*cur+1);
    	make(1+l+(r-l)/2,r,2*cur+2);
    	seg[cur].sum = seg[2*cur+1].sum + seg[2*cur+2].sum;
    	seg[cur].pre = maxx(seg[2*cur+1].pre,seg[2*cur+1].sum+seg[2*cur+2].pre);
    	seg[cur].suf = maxx(seg[2*cur+2].suf,seg[2*cur+1].suf+seg[2*cur+2].sum);
    	seg[cur].ans = maxx(maxx(seg[2*cur+1].ans,seg[2*cur+2].ans),seg[2*cur+1].suf+seg[2*cur+2].pre);
    }
     
    node query (int l, int r, int x, int y, int cur)
    {
    	if (l <= x && y <= r) return seg[cur];
    	int mid = x + (y - x) / 2;
    	if (r <= mid) return query(l,r,x,mid,2*cur+1);
    	if (l > mid) return query(l,r,mid+1,y,2*cur+2);
    	node n1 = query(l,mid,x,mid,2*cur+1);
    	node n2 = query(mid+1,r,mid+1,y,2*cur+2);
    	node t;
    	t.sum = n1.sum + n2.sum;
    	t.pre = maxx(n1.pre,n1.sum+n2.pre);
    	t.suf = maxx(n2.suf,n1.suf+n2.sum);
    	t.ans = maxx(maxx(n1.ans,n2.ans),n1.suf+n2.pre);	
    	return t;
    }
     
    int main ()
    {
    	int n;
    	scanf("%d",&n);
    	for (int i=0; i<n; i++) scanf("%lld",&arr[i]);
    	make(0,n-1,0);
    	int m;
    	scanf("%d",&m);
    	int l, r;
    	while (m--) 
    	{
    		scanf("%d %d",&l,&r);
    		printf("%lld\n",query(l-1,r-1,0,n-1,0).ans);
    	}
    	return 0;
    } 
