    #include<bits/stdc++.h>
    using namespace std;
    int a[100005];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		int curmax=0, l=1, r=0, cursum=0, ansindl=-1, ansindr=-1;
     
    		while(r<=n){
    			r++;
    			cursum+=a[r];
    			if(cursum>curmax){
    				curmax=cursum;
    				ansindl=l;
    				ansindr=r;
    			}
     
    			if(cursum<0){
    				l=r+1;
    				cursum=0;
    			}
    		}
    		// printf("%d %d\n", ansindl, ansindr);
    		int ans=0;
    		if(curmax<=0){
    			for(int i=1;i<=n;i++){
    				ans+=(-a[i]);
    			}
    		}
    		else{
    			ans+=curmax;
    			for(int i=1;i<ansindl;i++){
    				ans+=(-a[i]);
    			}
    			for(int i=ansindr+1;i<=n;i++){
    				ans+=(-a[i]);
    			}
    		}
    		printf("%d\n", ans);
    	}
    	return 0;
    } 