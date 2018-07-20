    #include<stdio.h>
    using namespace std;
    long long ans=0;
    void fn(int n){
    	for(int i=1;i*i<=n;i++){
    		if(n%i==0){
    			ans++;
    		}
    	}
    }
    int main(){
    	int n;
    	scanf("%d", &n);
    	for(int i=1;i<=n;i++){
    		fn(i);
    	}
    	printf("%lld\n", ans);
    	return 0;
    } 
