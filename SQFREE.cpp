    #include<stdio.h>
    using namespace std;
    int mu[10000001];
    void pre(){
    	mu[1]=1;
    	for(int i=1;i<1e7+1;i++){
    		for(int j=i+i;j<1e7+1;j+=i){
    			mu[j]-=mu[i];
    		}
    	}
    }
    int main(){
    	pre();
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n, ans=0;
    		scanf("%lld", &n);
    		for(long long int i=1;i*i<=n;i++){
    			ans+=(mu[i])*(n/((i*i)));
    		}
    		printf("%lld\n", ans);
    	}
    	return 0;
    } 
