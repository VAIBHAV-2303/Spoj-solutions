    #include<bits/stdc++.h>
    using namespace std;
    int a[105];
    int main(){
    	int n;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    	}
     
    	sort(a, a+n);
     
    	if(a[0]==a[n-1]){
    		if(a[0]==n-1){
    			printf("%d\n", n);
    		}
    		else if(a[0]==0){
    			printf("0\n");
    		}
    		else{
    			printf("-1\n");
    		}
    	}
    	else if(a[0]==a[n-1]-1){
    		int count=1;
    		for(int i=n-2;i>=0;i--){
    			if(a[i]!=a[i+1]){
    				break;
    			}
    			count++;
    		}
    		if(n-count==a[n-1]){
    			printf("%d\n", n-count);
    		}
    		else{
    			printf("-1\n");
    		}
    	}
    	else{
    		printf("-1\n");
    	}
    	return 0;
    } 