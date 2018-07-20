    #include<stdio.h>
    using namespace std;
    int gcd(int a, int b){
    	if(b==0){
    		return a;
    	}
    	return gcd(b, a%b);
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		int a, b, c;
    		scanf("%d %d %d", &a, &b, &c);
     
    		if(c%gcd(a, b)==0){
    			printf("Case %d: Yes\n", t);
    		}
    		else{
    			printf("Case %d: No\n", t);
    		}
    	}
    	return 0;
    } 
