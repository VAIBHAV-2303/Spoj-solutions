    #include<stdio.h>
    #include<math.h>
    using namespace std;
    int main(){int T;scanf("%d",&T);while(T--){long long i, a;scanf("%lld",&a);i=(long long)sqrt(1.0*(a*a+1));while((a*a+1)%i){i--;}printf("%lld\n", 2*a+i+((a*a+1)/i));}return 0;} 
