    #include<stdio.h>
    using namespace std;
    int G[1004][1004];
    int mat[1004][1004];
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int n, m, k, u, v;
    		scanf("%d %d %d", &n, &m, &k);
     
    		for(int i=0;i<1004;i++){
    			for(int j=0;j<1004;j++){
    				G[i][j]=0;
    			}
    		}
    		while(k--){
    			scanf("%d %d", &u, &v);
    			G[u][v]++;
    		}
     
    		for(int i=1;i<=n;i++){
    			mat[i][1]=G[i][1];
    			for(int j=2;j<=m;j++){
    				mat[i][j]=mat[i][j-1]+G[i][j];
    			}
    		}
    		int temp=0; 
    		long long ans=0;
    		for(int i=1;i<m;i++){
    			temp=0;
    			for(int j=1;j<n;j++){
    				temp+=mat[j][m]-mat[j][i];
    				ans+=G[j+1][i]*temp;
    			}
    		}
    		/*temp=0;
    		for(int i=2;i<=m;i++){
    			temp=mat[n][i-1];
    			for(int j=n-1;j>=1;j--){	
    				ans+=G[j][i]*temp;
    				temp+=mat[j][i-1];
    			}
    		}*/
    		printf("Test case %d: %lld\n", t, ans);
     
    	}
    	return 0;
    } 
