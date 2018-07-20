    #include<stdio.h>
    #include<math.h>
    using namespace std;
    long long a[23];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		long long m, x=0, t, temp, currmax=0;
    		scanf("%d %lld", &n, &m);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &a[i]);
    		}
    		long long bound=(long long)pow(2, n);
     
    		while(x<bound){
    			x++;
    			t=x;
    			temp=0;
    			for(int i=0;i<n;i++){
    				if(t&1){
    					temp+=a[i];
    				}
    				t=t/2;
    			}
    			if(temp<=m && temp>currmax){
    				currmax=temp;
    			}
    		}
    		printf("%lld\n", currmax);
    	}
    	return 0;
    } 
