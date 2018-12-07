    #pragma GCC optimize ("O3")
    #include<bits/stdc++.h>
    using namespace std;
    int a[203], ans[103], R[103];
    void fn(int l, int r){
    	int i=l+1;
    	while(i!=r){
    		fn(i, R[a[i]]);
    		ans[a[l]]++;
    		i=R[a[i]]+1;	
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		for(int i=0;i<103;i++){
    			ans[i]=0;
    		}
    		int n, pui;
    		scanf("%d", &n);
    		pui=n<<1;
    		for(int i=0;i<pui;i++){
    			scanf("%d", &a[i]);
    			R[a[i]]=i;
    		}
    		fn(0, pui-1);
    		printf("Case %d:\n", t);
    		for(int i=1;i<=n;i++){
    			printf("%d -> %d\n", i, ans[i]);
    		}
     
    	}
    	return 0;
    } 