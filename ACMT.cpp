    #include<stdio.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, e, ans=0;
    		scanf("%d %d", &e, &n);
     
    		while((n>=1 && e>=2) || (e>=1 && n>=2)){
    			if(n>e){
    				n-=2;
    				e--;
    			}
    			else{
    				e-=2;
    				n--;
    			}
    			ans++;
    		}
    		printf("%d\n", ans);
    	}
    	return 0;
    } 
