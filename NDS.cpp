    #include<bits/stdc++.h>
    using namespace std;
    int a[1000006], li[1000006];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, l, r, mid, maxsize=1, L;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
    		scanf("%d", &L);
    		li[1]=a[0];
    		for(int i=1;i<n;i++){
     
    			if(a[i]<li[1]){
    				li[1]=a[i];
    			}
    			else if(a[i]>li[maxsize]){
    				maxsize++;
    				li[maxsize]=a[i];
    			}
    			else{
    				l=1, r=maxsize;
    				while(l<=r){
    					if(l==r){
    						li[l]==a[i];
    						break;
    					}
    					if(r-l==1){
    						if(li[l]>=a[i]){
    							li[l]=a[i];
    						}
    						else{
    							li[r]=a[i];
    						}
    						break;
    					}
     
    					mid=(l+r)/2;
    					if(li[mid]>a[i]){
    						r=mid;
    					}
    					else{
    						l=mid;
    					}
    				}
    			}
    			// for(int i=1;i<=maxsize;i++){
    				// printf("%d ", li[i]);
    			// }
    			// printf("\n");
    		}
     
    		if(maxsize<L){
    			printf("-1\n");
    		}
    		else{
    			printf("%d\n", li[L]);
    		}
    	}
    	return 0;
    } 