    #include <stdio.h>
    int main(){
        int t;
        scanf("%d", &t);
        for(int tc = 1; tc <= t; ++tc){
            long long int a, b, c;
            scanf("%lld %lld %lld", &a, &b, &c);
            long long result = 0;
            result+=((b*(b+1))/2);
            // printf("%lld\n", result);
            result*=((c*(c+1))/2);
            // printf("%lld\n", result);
            result*=a;
            printf("Case %d: %lld\n", tc, result);
        }
        return 0;
    } 
