    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int n, c1=0, c2=0, c3=0, c4=0,c5=0, x;
    		scanf("%d", &n);
    		while(n--){
    			scanf("%d", &x);
    			if(x==1){
    				c1++;
    			}
    			else if(x==2){
    				c2++;
    			}
    			else if(x==3){
    				c3++;
    			}
    			else if(x==4){
    				c4++;
    			}
    			else{
    				c5++;
    			}
    		}
     
    		printf("Case %d: %d\n", t, max(c1+min(c2, c3)+min(c4, c5), max(c2+min(c1+min(c4, c5), c3), max(c3+min(c1+min(c4, c5), c2), max(c4+min(c1+min(c2, c3), c5), c5+min(c1+min(c2, c3), c4) )))));
     
    	}
    	return 0;
    } 
