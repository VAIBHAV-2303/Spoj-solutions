    #include<stdio.h>
    using namespace std;
    typedef struct Node{
    	int height;
    	int par;
    	int rel;
    }node;
    node dsu[50004];
    int find(int v){
    	if(dsu[v].par==-1){
    		return v;
    	}
    	return find(dsu[v].par);
    }
    int R(int v){
    	int res=0;
    	while(dsu[v].par!=-1){
    		res=(res+dsu[v].rel)%3;
    		v=dsu[v].par;
    	}
    	return res%3;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, k, ans=0;
    		scanf("%d %d", &n, &k);
     
    		for(int i=0;i<=n;i++){
    			dsu[i].height=0;
    			dsu[i].par=-1;
    			dsu[i].rel=0;
    		}
    		int ch, x, y, rx, ry, relrx, relry;
    		while(k--){
    			scanf("%d %d %d", &ch, &x, &y);
    			if(x>n || y>n){
    				ans++;
    				// printf("%d\n", ans);
    				continue;
    			}
    			rx=find(x);
    			ry=find(y);
    			if(ch==1){
    				if(rx==ry){
    					if( ((R(x)-R(y)+3)%3) != 0){
    						ans++;
    					}
    				}
    				else{
    					if(dsu[rx].height>dsu[ry].height){
    						dsu[ry].rel=(R(x)-R(y)+3)%3;
    						dsu[ry].par=rx;
    					}
    					else if(dsu[ry].height>dsu[rx].height){
    						dsu[rx].rel=(R(y)-R(x)+3)%3;
    						dsu[rx].par=ry;
    					}
    					else{
    						dsu[ry].rel=(R(x)-R(y)+3)%3;
    						dsu[ry].par=rx;
    						dsu[rx].height++;	
    					}
    				}
    			}
    			else{
    				if(x==y){
    					ans++;
    					// printf("%d\n", ans);
    					continue;
    				}
    				// printf("pui\n");
    				if(rx==ry){
    					if( ((R(x)-R(y)+3)%3) != 1){
    						ans++;
    					}
    				}
    				else{
    					if(dsu[rx].height>dsu[ry].height){
    						dsu[ry].rel=(((R(x)-R(y)+3)%3)+2)%3;
    						dsu[ry].par=rx;
    					}
    					else if(dsu[ry].height>dsu[rx].height){
    						dsu[rx].rel=(((R(y)-R(x)+3)%3)+1)%3;
    						dsu[rx].par=ry;
    					}
    					else{
    						dsu[ry].rel=(((R(x)-R(y)+3)%3)+2)%3;
    						dsu[ry].par=rx;	
    						dsu[rx].height++;	
    					}
    				}
    				// printf("%d\n", ans);
    			}
    		}
    		printf("%d\n", ans);
    	}
    	return 0;
    } 
