    #include<stdio.h>
    int main(){
    	long long int a, b, temp, ans;
    	while(scanf("%lld %lld", &a, &b)!=EOF){
    		if(a>b){
    			temp=a;
    			a=b;
    			b=temp;
    		}
    		ans=0;
     
    		if(a<0 && b<0){
    			a*=-1;
    			b*=-1;
    			ans+=( ((b*(b-1))/2) - ((a*(a+1))/2) );
    		}
    		else if (a<0){
    			a*=-1;
    			ans+=(-1)*((a*(a+1))/2);
    			ans+=((b*(b+1))/2);
    		}
    		else{
    			ans+=( ((b*(b+1))/2) - ((a*(a-1))/2) );
    		}
    		printf("%lld\n", ans);
    	}
    	return 0;
    }   