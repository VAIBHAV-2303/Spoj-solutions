    #include<stdio.h>
    int max(int x, int y){
    	if(y>x){
    		return y;
    	}
    	return x;
    }
    int main(){
    	int a[1005][1005];
    	int pui[1005];
    	for(int t=1;0<1;t++){
    		int n, ans=0, total=0;
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
     
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				scanf("%d", &a[i][j]);
    				total+=a[i][j];
    			}
    			pui[i]=0;
    		}
     
    		for(int i=0;i<n;i++){
    			for(int j=0;j<n;j++){
    				pui[i]+=a[i][j];
    				pui[j]-=a[i][j];
    			}
    		}
     
    		for(int i=0;i<n;i++){
    			ans+=max(0, pui[i]);
    		}
    		printf("%d. %d %d\n", t, total, ans);
     
    	}
    	return 0;
    } 
