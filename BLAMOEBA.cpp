        #include<stdio.h>
        using namespace std;
        long long gcd(long long x, long long y){
            if(y==0){
                return x;
            }
            return gcd(y, x%y);
        }
        void mul(unsigned long long int a[][2], unsigned long long int b[][2]){
        	unsigned long long int m=1e9+7, i, j;
        	unsigned long long int c[2][2];
        	for(i=0;i<4;i++){
        		c[0][i]=0;
        	}
        	c[0][0]=(((a[0][0]%m)*(b[0][0]%m)%m)+((a[0][1]%m)*(b[1][0]%m)%m))%m;
        	c[0][1]=(((a[0][0]%m)*(b[0][1]%m)%m)+((a[0][1]%m)*(b[1][1]%m)%m))%m;
        	c[1][0]=(((a[1][0]%m)*(b[0][0]%m)%m)+((a[1][1]%m)*(b[1][0]%m)%m))%m;
        	c[1][1]=(((a[1][0]%m)*(b[0][1]%m)%m)+((a[1][1]%m)*(b[1][1]%m)%m))%m;
         
        	for(i=0;i<2;i++){
        		for(j=0;j<2;j++){
        			a[i][j]=c[i][j]%m;
        		}
        	}
        }
        int main(){
        	int T;
        	scanf("%d", &T);
        	while(T--){
        		unsigned long long int m=1e9+7;
        		unsigned long long int n, k;
        		scanf("%llu %llu", &k, &n);
        		unsigned long long int a[2][2], ans[2][2];
        		ans[0][0]=1;
        		ans[0][1]=0;
        		ans[1][0]=0;
        		ans[1][1]=1;
        		a[0][0]=k;
        		a[0][1]=1;
        		a[1][0]=0;
        		a[1][1]=1;
         
        		while(n>=1){
        			if(n%2==1){
        				mul(ans, a);
        			}
        			n=n/2;
        			mul(a, a);
        		}
        		
                printf("%llu %llu\n", ans[0][1], ans[0][0]);
     
        	}
        	return  0;
        }  
