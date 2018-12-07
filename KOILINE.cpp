    #include<bits/stdc++.h>
    using namespace std;
    int sorted[100005], a[100005], seg[400020], ans[100005];
    int create(int s, int e, int ind){
    	if(s==e){
    		return 1;
    	}
    	seg[2*ind]=create(s, (s+e)/2, 2*ind);
    	seg[2*ind+1]=create(((s+e)/2)+1, e, 2*ind+1);
     
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
    void update(int l, int r, int s, int e, int ind){
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
    		return update(l, r, ((s+e)/2)+1, e, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return update(l, r, s, (s+e)/2, 2*ind);
    	}
    	else{
    		update(l, (s+e)/2, s, (s+e)/2, 2*ind);
    		update(((s+e)/2+1), r, ((s+e)/2+1), e, 2*ind+1);
    	}
    }
    int main(){
    	int n, l, r, mid, ansind;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &sorted[i]);
    	}
    	sort(sorted, sorted+n);
     
    	seg[1]=create(0, n-1, 1);
     
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    	}
     
    	for(int i=n-1;i>=0;i--){
    		l=0, r=n-1;
    		while(r>=l){
    			if(r==l){
    				ansind=l;
    				break;
    			}
    			if(r-l==1){
    				if(Search(0, l, 0, n-1, 1)==a[i]+1){
    					ansind=l;
    				}
    				else{
    					ansind=r;
    				}
    				break;
    			}
    			mid=(l+r)/2;
    			if(Search(0, mid, 0, n-1, 1)>=a[i]+1){
    				r=mid;
    			}
    			else{
    				l=mid;
    			}
    		}
    		ans[i]=sorted[ansind];
    		update(ansind, ansind, 0, n-1, 1);
    	}
     
    	for(int i=0;i<n;i++){
    		printf("%d\n", ans[i]);
    	}
    	return 0;
    } 