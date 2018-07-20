    #include<stdio.h>
    #include<math.h>
    #include<cmath>
    using namespace std;
    double a[10005];
    int n, f;
    int check(long double p){
    	int count=0; 
    	for(int i=0;i<n;i++){
    		count+=(int)floor(a[i]/p);
    		if(count>f){
    			return 1;
    		}
    	}
    	return 0;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int temp;
    		scanf("%d %d", &n, &f);
    		for(int i=0;i<n;i++){
    			scanf("%d", &temp);
    			a[i]=temp*temp*M_PI;
    		}
     
    		double l=0, r=1000000000, mid;
     
    		for(int i=0;i<100;i++){
    			mid=(l+r)/2;
     
    			if(check(mid)==1){
    				l=mid;
    			}
    			else{
    				r=mid;
    			}
    		}
    		printf("%.4f\n", mid);
    	}
    	return 0;
    } 
