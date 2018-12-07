    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, flag=0;
    		long long x, cur=1;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &x);
    			cur-=x;
    			if(cur<0){
    				flag=1;
    			}
    			else{
    				cur<<=1;
    			}
    		}
     
    		if(flag || cur!=0){
    			printf("No\n");
    		}
    		else{
    			printf("Yes\n");
    		}
    	}
    	return 0;
    } 