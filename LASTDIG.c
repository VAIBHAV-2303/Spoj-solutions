    #include<stdio.h>
    #include<math.h>
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int a, x, period=1;
    		long long b;
    		scanf("%d %lld", &a, &b);
    		if(b==0){
    			printf("1\n");
    			continue;
    		}
    		a=a%10;
    		x=a;
    		x=a*a;
    		while((x%10)!=a){
    			x=x*a;
    			period++;
    		}
    		x=1;
    		b--;
    		b=b%period;
     
    		x=a;
     
    		for(int i=0;i<b;i++){
    			x=x*a;
    		}
     
    		printf("%d\n", x%10);
     
    	}
    	return 0;
    } 
