    #include<stdio.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n;
    		long long temp, tot=0;
    		scanf("%d", &n);
     
    		for(int i=0;i<n;i++){
    			scanf("%lld", &temp);
    			tot+=temp%n;
    		}
    		if(tot%n==0){
    			printf("YES\n");
    		}
    		else{
    			printf("NO\n");
    		}
    	}
    	return 0;
    } 
