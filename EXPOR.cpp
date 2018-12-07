    #include<stdio.h>
    unsigned long long a[100005][32];
    unsigned long long gcd(unsigned long long x, unsigned long long y){
        if(x==0){
            return y;
        }
        return gcd(y%x, x);
    }
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            unsigned long long n, x, y;
            scanf("%llu", &n);
     
            for(int i=0;i<n;i++){
                scanf("%llu", &x);
                y=1;
                for(int j=0;j<32;j++){
                    if(x&y){
                        a[i][j]=1;
                    }
                    else{
                        a[i][j]=0;
                    }
                    y<<=1;
                }
            }
     
            for(int i=1;i<n;i++){
                for(int j=0;j<32;j++){
                    a[i][j]+=a[i-1][j];
                }   
            }
     
            unsigned long long num=0, den=(n*(n-1))/2;
            for(unsigned long long i=n-1;i>=1;i--){
                y=1;
                for(int j=0;j<32;j++){
                    if(a[i][j]>0){
                        if(a[i-1][j]+1==a[i][j]){
                            num+=(y*i);
                        }
                        else{
                            num+=(a[i-1][j]*y);
                        }
                    }
                    y<<=1;
                }
            }
     
            printf("%llu/%llu\n", num/gcd(num, den), den/gcd(num, den));
        }
        return 0;
    } 