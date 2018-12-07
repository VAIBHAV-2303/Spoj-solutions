    #include<bits/stdc++.h>
    using namespace std;
    int a[100005], ans[100005], seg[400020];
    int create(int l, int r, int ind){
    	if(l==r){
    		return 1;
    	}
    	seg[2*ind]=create(l, (l+r)/2, 2*ind);
    	seg[2*ind+1]=create(((l+r)/2)+1, r, 2*ind+1);
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
    void Update(int l, int r, int s, int e, int ind){
    	if(l<=s&&r>=e){
    		seg[ind]=0;
    		ind>>=1;
    		while(ind!=0){
    			seg[ind]=seg[2*ind]+seg[2*ind+1];
    			ind>>=1;
    		}
    		return;
    	}
    	if(l>(s+e)/2){
    		return Update(l, r, (s+e)/2+1, e, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return Update(l, r, s, (s+e)/2, 2*ind);
    	}
    }
    int main(){
    	int T, flag;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		flag=0;
    		int n;
    		scanf("%d", &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d", &a[i]);
    		}
    		seg[1]=create(1, n, 1);
     
    		for(int i=n;i>=1;i--){
     
    			if(i<=a[i] || Search(1, n, 1, n, 1)<i-a[i]){
    				flag=1;
    				break;
    			}
     
    			int l=1, r=n, mid;
    			while(r>=l){
    				if(r==l){
    					ans[i]=l;
    					break;
    				}
    				if(r-l==1){
    					if(Search(1, l, 1, n, 1)>=i-a[i]){
    						ans[i]=l;
    					}
    					else{
    						ans[i]=r;
    					}
    					break;
    				}
     
    				mid=(l+r)/2;
    				if(Search(1, mid, 1, n, 1)>=i-a[i]){
    					r=mid;
    				}
    				else{
    					l=mid;
    				}
    			}
    			Update(ans[i], ans[i], 1, n, 1);
    		}
     
    		printf("Test : %d\n", t);
    		if(flag==0){
    			for(int i=1;i<=n;i++){
    				printf("%d ", ans[i]);
    			}
    			printf("\n");
    		}
    		else{
    			printf("-1\n");
    		}
    	}
    	return 0;
    } 