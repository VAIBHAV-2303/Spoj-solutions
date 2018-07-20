    #include<stdio.h>
    using namespace std;
    int main(){
        while(1){
            int n;
            scanf("%d", &n);
            if(n==0){
                break;
            }
     
            printf("%d\n", (int)(((3*n*n + 5*n)/2)+1));
        }
        return 0;
    } 
