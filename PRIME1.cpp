    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    void generate(){
        primes.push_back(2);
        int isprime;
        for(int i=3;i<100000;i+=2){
            isprime=1;
            for(int j=0;primes[j]*primes[j]<=i;j++){
                if(i%primes[j]==0){
                    isprime=0;
                    break;
                }
            }
            if(isprime){
                primes.push_back(i);
            }
        }
    }
    int main(){
        generate();
     
        int T, isprime;
        scanf("%d", &T);
        while(T--){
            long long n, m, i;
            scanf("%lld %lld", &n, &m);
            for(i=max((long long)2, n);i<=m;i++){
                isprime=1;
                for(int j=0;primes[j]*primes[j]<=i;j++){
                    if(i%primes[j]==0){
                        isprime=0;
                        break;
                    }
                }
                if(isprime){
                    printf("%lld\n", i);
                }
            }
            printf("\n");
        }
        return 0;
    } 
