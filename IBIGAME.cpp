    #include<stdio.h>
    int main(){
    	int T;
    	scanf("%d", &T);
    	unsigned long long a, b;
        while(T--){
        	scanf("%llu %llu", &a, &b);
    		if(a<=b){
        		if(b-a<=1){
        			printf("Farael\n");
        		}
    			else{
        			a+=2;
                    if((b-a)%8 == 5 || (b-a)%8 == 6 || (b-a)%8 == 7){
                        printf("Farael\n");
                    }
                    else{
                        printf("Ziya\n");
                    }
        		}
    		}
        	else{
        		if(a-b<=1){
    				printf("Farael\n");
        		}
        		else{
       			  b+=2;
                    if((a-b)%8 == 5 || (a-b)%8 == 6 || (a-b)%8 == 7){
                        printf("Farael\n");
                    }
                    else{
                        printf("Ziya\n");
                    }	
    			}
    		}
    	}
    	return 0;
    } 
     
     
