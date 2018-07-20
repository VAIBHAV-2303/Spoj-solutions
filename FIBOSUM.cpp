     
    #include<stdio.h>
    using namespace std;
    long long m=1e9+7;
    long long fibm[2][2], ans[2][2];
    void mul(char x, long long int b[][2]){
    	long long int i, j;
    	long long int c[2][2];
    	for(i=0;i<4;i++){
    		c[0][i]=0;
    	}
    	
    	if(x=='f'){
    		c[0][0]=(((fibm[0][0]%m)*(b[0][0]%m)%m)+((fibm[0][1]%m)*(b[1][0]%m)%m))%m;
    		c[0][1]=(((fibm[0][0]%m)*(b[0][1]%m)%m)+((fibm[0][1]%m)*(b[1][1]%m)%m))%m;
    		c[1][0]=(((fibm[1][0]%m)*(b[0][0]%m)%m)+((fibm[1][1]%m)*(b[1][0]%m)%m))%m;
    		c[1][1]=(((fibm[1][0]%m)*(b[0][1]%m)%m)+((fibm[1][1]%m)*(b[1][1]%m)%m))%m;
     
    		for(i=0;i<2;i++){
    			for(j=0;j<2;j++){
    				fibm[i][j]=c[i][j];
    			}
    		}
    	}
    	else{
    		c[0][0]=(((ans[0][0]%m)*(b[0][0]%m)%m)+((ans[0][1]%m)*(b[1][0]%m)%m))%m;
    		c[0][1]=(((ans[0][0]%m)*(b[0][1]%m)%m)+((ans[0][1]%m)*(b[1][1]%m)%m))%m;
    		c[1][0]=(((ans[1][0]%m)*(b[0][0]%m)%m)+((ans[1][1]%m)*(b[1][0]%m)%m))%m;
    		c[1][1]=(((ans[1][0]%m)*(b[0][1]%m)%m)+((ans[1][1]%m)*(b[1][1]%m)%m))%m;
     
    		for(i=0;i<2;i++){
    			for(j=0;j<2;j++){
    				ans[i][j]=c[i][j];
    			}
    		}
    	}
    }
    long long fib(long long n){
    	fibm[0][0]=1;
    	fibm[0][1]=1;
    	fibm[1][0]=1;
    	fibm[1][1]=0;
    	ans[0][0]=1;
    	ans[0][1]=0;
    	ans[1][0]=0;
    	ans[1][1]=1;
     
    	while(n>0){
    		if(n%2==1){
    			mul('a', fibm);
    		}
    		n=n/2;
    		mul('f', fibm);
    	}
    	return ans[0][1]%m;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long l, r, pui, chui;
    		scanf("%lld %lld", &l, &r);
    		if(l<=1){
    			printf("%lld\n", (fib(r+2)-1)%m);
    		}
    		else{
    			pui=((fib(r+2)-1)+m)%m;
    			chui=((fib(l+1)-1)+m)%m;
    			printf("%lld\n", ((pui-chui)+m)%m);
    		}
    	}
    	return 0;
    } 
