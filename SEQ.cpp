    #include<stdio.h>
    using namespace std;
    long long trans[14][14];
    long long iden[14];
    long long aux[14][14];
    long long m=1e9;
    void mul(char x, int dim){
    	long long temp[14][14]={0};
    	if(x=='a'){
    		for(int i=0;i<dim;i++){
    			for(int j=0;j<dim;j++){
    				for(int t=0;t<dim;t++){
    					temp[i][j]=((temp[i][j]%m)+((aux[i][t]%m)*(trans[t][j]%m))%m)%m;
    				}
    			}
    		}
    		for(int i=0;i<dim;i++){
    			for(int j=0;j<dim;j++){
    				aux[i][j]=temp[i][j];
    			}
    		}
    	}
    	else{
    		for(int i=0;i<dim;i++){
    			for(int j=0;j<dim;j++){
    				for(int t=0;t<dim;t++){
    					temp[i][j]=((temp[i][j]%m)+((trans[i][t]%m)*(trans[t][j]%m))%m)%m;
    				}
    			}
    		}
    		for(int i=0;i<dim;i++){
    			for(int j=0;j<dim;j++){
    				trans[i][j]=temp[i][j];
    			}
    		}
    	}
    }
    void power(long long int y, int dim){
    	for(int i=0;i<dim;i++){
    		for(int j=0;j<dim;j++){
    			if(i==j){
    				aux[i][j]=1;
    			}
    			else{
    				aux[i][j]=0;
    			}
    		}
    	}
     
    	while(y>0){
    		if(y&1){
    			mul('a', dim);
    		}
    		y=y/2;
    		mul('t', dim);
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int k;
    		long long n, ans=0;
    		scanf("%d", &k);
    		for(int i=0;i<k;i++){
    			scanf("%lld", &iden[i]);
    		}
    		for(int i=0;i<k;i++){
    			scanf("%lld", &trans[0][i]);
    		}
    		for(int i=1;i<k;i++){
    			for(int j=0;j<k;j++){
    				if(j==i-1){
    					trans[i][j]=1;
    				}
    				else{
    					trans[i][j]=0;
    				}
    			}
    		}
     
    		scanf("%lld", &n);
    		if(n<=k){
    			printf("%lld\n", iden[n-1]%m);
    			continue;
    		}
     
    		power(n-k, k);
     
    		for(int i=0;i<k;i++){
    			ans=((ans%m) + (((aux[0][i]%m)*(iden[k-i-1]%m))%m) )%m;
    		}
    		printf("%lld\n", ans);
    	}
    	return 0;
    }
     
