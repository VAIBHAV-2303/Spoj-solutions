    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		scanf("%d", &n);
    		for(int i=1, j=2;i<=n;i++, j+=2){
    			if(j>n){
    				j=1;
    			}
    			printf("%d %d\n", i, j);
    		}
    	}
    	return 0;
    } 