    #include<bits/stdc++.h>
    #include<stdio.h>
    using namespace std;
    long long m=1000000007;
    int main(){
      int T;
      scanf("%d", &T);
      while(T--){
       long long n, i;
       scanf("%lld", &n);
       long long ans = 0;
       long long last;
       for(i=1;i*i<=n;i++){
         ans=(ans + (i * (n/i))%m)%m;
       }
       i--;
       last=n/i;
       for(i=1;i<last;i++){
        long long en=n/i;
        long long st=n/(i+1);
        long long diff=(en*(en+1)/2 )-(st*(st+1)/2);
        ans=(ans + (i*diff)%m)%m;
      }
      printf("%lld\n", ans);
    }
     
    return 0;
     
    } 
