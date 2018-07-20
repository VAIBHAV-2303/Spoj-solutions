    #include<stdio.h>
    long long m=1e9+7;
    long long arr[10000001];
    int main(){
        arr[1]=0;
        for(long long int i=2;i<10000001;i++){
            if(i&1){
                arr[i]=((i*arr[i-1])%m - 1 + m)%m;
            }
            else{
                arr[i]=((i*arr[i-1])%m + 1)%m;
            }
        }
        int T;
        long long n;
        scanf("%d", &T);
        while(T--){
            scanf("%lld", &n);
            printf("%lld\n", arr[n]);
        }
        return 0;
    } 
