    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int csum[105][50003]={0};
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int k, h, n, x, l, r;
    		scanf("%d %d %d", &k, &h, &n);
    		for(int i=0;i<k;i++){
    			for(int j=1;j<=n;j++){
    				scanf("%d", &x);
    				csum[i][j]=csum[i][j-1]+x;
    			}
    		}
    		int q, st, unst;
    		scanf("%d", &q);
     
    		while(q--){
    			scanf("%d %d", &l, &r);
    			st=0;
    			unst=0;
    			for(int i=0;i<k;i++){
    				if(csum[i][r]-csum[i][l-1]<=h){
    					unst++;
    				}
    				else{
    					st++;
    				}
    			}
    			printf("%d - %d\n", st, unst);
    		}
    	}
    	return 0;
    } 
