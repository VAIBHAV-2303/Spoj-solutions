    #include<stdio.h>
    using namespace std;
    long long int gcd(long long int a, long long int b){
    	if(b==0){
    		return a;
    	}
    	return gcd(b, a%b);
    }
    int main(){
    	long long int n, k, den, num;
    	while(1){
    		scanf("%lld %lld", &n, &k);
    		if(n==-1 && k==-1){
    			break;
    		}
    		if(k<=2){
    			printf("0\n");
    			continue;
    		}
     
    		if(k%2==1){
    			num=((k/2)*(k/2));
    		}
    		else{
    			num=(((k-1)/2)*((k+1)/2));
    		}
     
    		den=(n*(n-1))/2;
     
    		if(num>=den){
    			printf("1\n");
    		}
    		else{
    			printf("%lld/%lld\n", num/gcd(num, den), den/gcd(num, den));
    		}
     
    	}
    	return 0;
    } 
