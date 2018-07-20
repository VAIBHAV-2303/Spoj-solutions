    #include<stdio.h>
    using namespace std;
    long long m=1e9+7;
    long long fibm[2][2], ans[2][2];
    long long power(long long x, long long y){
    	long long res=1;
    	while(y>0){
    		if(y%2==1){
    			res=((res%m)*(x%m))%m;
    		}
    		x=((x%m)*(x%m))%m;
    		y=y/2;
    	}
    	return res;
    }
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
    	return ans[0][1];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long n, x;
    		scanf("%lld  %lld", &n, &x);
     
    		long long a, b;
     
    		a=((fib(n)%m)*(power(x, n+2)%m))%m;
    		a=((a%m)+((fib(n+1)%m)*(power(x, n+1)%m))%m)%m;
    		a=(((a%m)-(x%m))+m)%m;
     
    		b=((x%m)*(x%m))%m;
    		b=((b%m)+(x%m))%m;
    		b=(((b%m)-(1%m))+m)%m;
     
    		a=((a%m)*(power(b, m-2)%m))%m;
     
    		printf("%lld\n", a);
     
    	}
    	return 0;
    } 
