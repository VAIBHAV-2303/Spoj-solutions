    #include<stdio.h>
    #include<string.h>
    #include<bits/stdc++.h>
    using namespace std;
    char a[1005];
    char b[1005];
    int dp[1005][1005];
    int n1, n2, k;
    int fn(int x, int y){
    	int pui;
    	if(dp[x][y]==-1){
    		if(x>=n1 || y>=n2){
    			dp[x][y]=0;
    		}
    		else{
    			int count=0;
    			for(int i=0;i+x<n1 && i+y<n2;i++){
    				if(a[x+i]!=b[y+i]){
    					break;
    				}
    				count++;
    			}
    			
    			pui=0;
    			if(count>=k){	
    				for(int i=k;i<=count;i++){
    					if(i+fn(x+i, y+i)>pui){
    						pui=i+fn(x+i, y+i);
    					}
    				}
    			}
    			dp[x][y]=max(fn(x+1, y), max(fn(x, y+1), pui));
    		}
    	}
    	return dp[x][y];
    }
    int main(){
    	while(1){
    		scanf("%d", &k);
    		if(k==0){
    			break;
    		}
     
    		scanf("%s", a);
    		scanf("%s", b);
    		n1=strlen(a);
    		n2=strlen(b);
     
    		for(int i=0;i<1005;i++){
    			for(int j=0;j<1005;j++){
    				dp[i][j]=-1;
    			}
    		}
     
    		printf("%d\n", fn(0, 0));
    	
    		/*for(int i=0;i<n1;i++){
    			for(int j=0;j<n2;j++){
    				printf("%d ", dp[i][j]);
    			}
    			printf("\n");
    		}*/
    	}
    	return 0;
    } 
