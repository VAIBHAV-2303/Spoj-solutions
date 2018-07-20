    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int A[15], D[15];
    int main(){
    	while(1){
    		int a, d;
    		scanf("%d %d", &a, &d);
    		if(a==0 && d==0){
    			break;
    		}
    		for(int i=0;i<a;i++){
    			scanf("%d", &A[i]);
    		}
    		for(int j=0;j<d;j++){
    			scanf("%d", &D[j]);
    		}
     
    		sort(A, A+a);
    		sort(D, D+d);
     
    		if(A[0]<D[1]){
    			printf("Y\n");
    		}
    		else{
    			printf("N\n");
    		}
     
    	}
    	return 0;
    } 
