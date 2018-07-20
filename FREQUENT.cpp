    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int seg[400005];
    int a[100005];
    int fn(int l, int r, int ind){
    	if(l==r){
    		return 1;
    	}
    	
    	seg[2*ind]=fn(l, (l+r)/2, 2*ind);
    	seg[2*ind+1]=fn(((l+r)/2)+1, r, 2*ind+1);
     
    	int pui=a[(l+r)/2], lcount=0, rcount=0;
     
    	for(int i=((l+r)/2)+1;i<=r;i++){
    		if(a[i]!=pui){
    			break;
    		}
    		rcount++;
    	}
    	for(int i=(l+r)/2;i>=l;i--){
    		if(a[i]!=pui){
    			break;
    		}
    		lcount++;
    	}
     
    	return max(lcount+rcount, max(seg[2*ind], seg[2*ind+1]));	
     
    }
    int search(int s, int e, int l, int r, int ind){
    	if(l<=s && r>=e){
    		return seg[ind];
    	}
    	if(l>(s+e)/2){
    		return search(((s+e)/2)+1, e, l, r, 2*ind+1);
    	}
    	if(r<=(s+e)/2){
    		return search(s, (s+e)/2, l, r, 2*ind);
    	}
    	else{
    		int pui=a[(s+e)/2], lcount=0, rcount=0;
     
    		for(int i=((s+e)/2)+1;i<=r;i++){
    			if(a[i]!=pui){
    				break;
    			}
    			rcount++;
    		}
    		for(int i=(s+e)/2;i>=l;i--){
    			if(a[i]!=pui){
    				break;
    			}
    			lcount++;
    		}
     
    		return max(lcount+rcount, max(search(s, (s+e)/2, l, (s+e)/2, 2*ind), search(((s+e)/2)+1, e, ((s+e)/2)+1, r, 2*ind+1)));		
    	}
    }
    int main(){
    	while(1){
    		int n, q, l, r;
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
    		scanf("%d", &q);
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		seg[1]=fn(0, n-1, 1);
     
    		/*for(int i=1;i<40;i++){
    			printf("%d ", seg[i]);
    		}
    		printf("\n");*/
     
    		while(q--){
    			scanf("%d %d", &l, &r);
    			printf("%d\n", search(0, n-1, l-1, r-1, 1));
    		}
    	}
    	return 0;
    } 
