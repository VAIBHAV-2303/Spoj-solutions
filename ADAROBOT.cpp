    #include<stdio.h>
    using namespace std;
    long long a[100000001];
    int fn(long long x){
    	long long pui=1;
    	int count=1;
    	while(1){
    		if(x&pui){
    			return count;
    		}
    		count++;
    		pui<<=1;
    	}
    }
    int main(){
    	a[0]=0;
    	int temp;
    	for(long long i=1;i<100000001;i++){
    		temp=fn((2*i)*(2*i-1));
    		a[i]=a[i-1]+temp*temp*temp;
    	}
    	// printf("pui\n");
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n;
    		scanf("%lld", &n);
    		printf("%lld\n", a[n/2]);
    	}
    	return 0;
    } 
