    #pragma GCC optimize ("O3")
    #pragma GCC push_options
    #pragma GCC optimize ("unroll-loops")
    #include<bits/stdc++.h>
    using namespace std;
    int a[200005], R[100005], curmax;
    int fn(int l, int r){
    	int i=l+1, count=0;
    	while(i!=r){
    		curmax=max(curmax, 1+fn(i, R[a[i]]));
    		count++;
    		i=R[a[i]]+1;
    	}
    	return count;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		curmax=0;
    		int n, pui;
    		scanf("%d", &n);
    		pui=n<<1;
    		for(int i=0;i<pui;i++){
    			scanf("%d", &a[i]);
    			R[a[i]]=i;
    		}
    		printf("%d\n", max(fn(0, 2*n-1), curmax));
    	}
    	return 0;
    } 