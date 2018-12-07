        #include<stdio.h>
        int main() {	
        	long long int n;
        	scanf("%lld", &n);
        	while(n>1 && n%2==0){
                n>>=1;
            }
            
            if(n>1){
                printf("NIE\n");
            }
            else{
                printf("TAK\n");
            }
     
        	return 0;
        }  