    #include<bits/stdc++.h>
    using namespace std;
    int main (){
    	int n, t;
    	scanf("%d %d", &n, &t);
    	t=t%4;
     
    	int arr[25][25], count=1;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			arr[i][j]=count;
    			count++;
    		}
    	}
     
    	if(t==0){
    		printf("Atef\n");
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				printf("%d ", arr[i][j]);
    			}
    			printf("\n");
    		}
    	}
    	else if(t==1){
    		printf("Sameh\n");
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				printf("%d ", arr[n-j-1][i]);
    			}
    			printf("\n");
    		}
    	}
    	else if(t==2){
    		printf("Ameen\n");
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				printf("%d ", arr[n-1-i][n-j-1]);
    			}
    			printf("\n");
    		}
    	}
    	else{
    		printf("Shafeek\n");
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				printf("%d ", arr[j][n-1-i]);
    			}
    			printf("\n");
    		}
    	}
    	return 0;
    } 