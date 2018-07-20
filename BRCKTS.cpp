    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int l;
    	int r;
    }node;
    node seg[120004];
    char s[30004];
    node fn(int l, int r, int ind){
    	node temp;
    	if(l==r){
    		if(s[l]=='('){
    			temp.l=0;
    			temp.r=1;
    		}
    		else{
    			temp.l=1;
    			temp.r=0;
    		}
    	}
    	else{
    		seg[2*ind]=fn(l, (l+r)/2, 2*ind);
    		seg[2*ind+1]=fn(1+((l+r)/2), r, 2*ind+1);
    		if(seg[2*ind].r>=seg[2*ind+1].l){
    			temp.r=seg[2*ind].r - seg[2*ind+1].l;
    			temp.r+=seg[2*ind+1].r;
    			temp.l=seg[2*ind].l;
    		}
    		else{
    			temp.r=seg[2*ind+1].r;
    			temp.l=seg[2*ind+1].l-seg[2*ind].r;
    			temp.l+=seg[2*ind].l;
    		}
    	}
    	return temp;
    }
    int search(int x, int l, int r, int ind){
    	if(l==r){
    		return ind;
    	}
    	else{
    		int mid=(l+r)/2;
    		if(x<=mid){
    			return search(x, l, (l+r)/2, 2*ind);
    		}
    		else{
    			return search(x, 1+((l+r)/2), r, 2*ind+1);
    		}
    	}
    }
    int main(){
    	int T=10;
    	while(T--){
    		int n, m, x;
    		scanf("%d", &n);
    		scanf("%s", s);
    		printf("Test %d:\n", 10-T);
     
    		seg[1]=fn(0, n-1, 1);
     
    		scanf("%d", &m);
    		while(m--){
    			scanf("%d", &x);
    			// printf("%d\n", x);
    			if(x==0){
    				// printf("pui\n");
    				if(seg[1].l==0 && seg[1].r==0){
    					printf("YES\n");
    				}
    				else{
    					printf("NO\n");
    				}
    			}
    			else{
    				x=search(x-1, 0, n-1, 1);
    				// printf("%d\n", x);
    				seg[x].l=1-seg[x].l;
    				seg[x].r=1-seg[x].r;
    				while(x!=1){
    					x=x/2;
    					// printf("%d\n", x);
    					if(seg[2*x].r>=seg[2*x+1].l){
    						seg[x].r=seg[2*x].r - seg[2*x+1].l;
    						seg[x].r+=seg[2*x+1].r;
    						seg[x].l=seg[2*x].l;
    					}
    					else{
    						seg[x].r=seg[2*x+1].r;
    						seg[x].l=seg[2*x+1].l-seg[2*x].r;
    						seg[x].l+=seg[2*x].l;
    					}
    				}
    			}
    			// printf("pui\n");
    		}
    	}
    	return 0;
    } 
