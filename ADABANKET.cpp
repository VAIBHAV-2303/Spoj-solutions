    #include<stdio.h>
    using namespace std;
    int main(){
    	int n, curmin=100000, temp, pui;
    	scanf("%d", &n);
    	for(int i=1;i<=n;i++){
    		temp=0;
    		for(int j=1;j<=n;j++){
    			scanf("%d", &pui);
    			temp+=pui;
    		}
    		if(temp<curmin){
    			curmin=temp;
    		}
    	}
     
    	printf("%d\n", 2*curmin);
     
    	return 0;
    } 
