    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, m;
    		scanf("%d %d", &n, &m);
     
    		int ans=0;
    		ans+=(m-1);
    		n--;
     
    		ans+=n*(2*(m-1) + 1);
    		printf("%d\n", ans);
    	}
    	return 0;
    } 