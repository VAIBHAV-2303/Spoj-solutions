    #include<bits/stdc++.h>
    using namespace std;
    set<int> S;
    int a[100005];
    int main(){
    	int n, k;
    	scanf("%d %d", &n, &k);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    		S.insert(a[i]);
    	}
    	int ans=0;
    	for(int i=0;i<n;i++){
    		if(S.find(a[i]+k)!=S.end()){
    			ans++;
    		}
    	}
    	printf("%d\n", ans);
    	return 0;
    } 