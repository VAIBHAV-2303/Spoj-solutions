    #include<bits/stdc++.h>
    #include<stdio.h>
    using namespace std;
    int main(){
    	long long n;
    	while(scanf("%lld", &n)!=EOF){
    		int iter=1;
    		long long x=5;
    		while(x<n){
    			n-=x;
    			x=x*2;
    			iter++;
    		}
    		// printf("%d\n", iter);
     
    		long long curr=(long long)pow(2, iter-1), pui=1;
     
    		while(n>curr){
    			n-=curr;
    			pui++;
    		}
     
    		if(pui==1){
    			printf("Asad\n");
    		}
    		if(pui==2){
    			printf("Foyj\n");
    		}
    		if(pui==3){
    			printf("Juwel\n");
    		}
    		if(pui==4){
    			printf("Mijan\n");
    		}
    		if(pui==5){
    			printf("Tanmay\n");
    		}
     
    	}
    	return 0;
    } 
