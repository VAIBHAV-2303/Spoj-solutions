    #include <iostream>
    #include<stdio.h>
    using namespace std;
    int main() {
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, temp;
    		long long total=0;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &temp);
    			total+=temp;
    		}
    		if(total%n==0){
    			printf("%d\n", n);
    		}
    		else{
    			printf("%d\n", n-1);
    		}
    	}
    	return 0;
    }  
