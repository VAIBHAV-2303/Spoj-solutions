    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    int isprime(long long int n){
        if(n==0 || n==1){
            return 0;
        }
        for(int i=0;1LL*primes[i]*primes[i]<=n;i++){
            if(n%primes[i]==0){
                return 0;
            }
        }
        return 1;
    }
    int main(){
        primes.push_back(2);
        int pui;
        for(int i=3;i<100005;i+=2){
            pui=1;
            for(int j=0;primes[j]*primes[j]<=i;j++){
                if(i%primes[j]==0){
                    pui=0;
                    break;
                }
            }
            if(pui){
                primes.push_back(i);
            }
        }
     
        long long int l, r;
        long long ans=0;
        scanf("%lld %lld", &l, &r);
     
        for(long long int i=r;i>l;i--){
            if(isprime(i)){
                ans+=i;
                l=i;
                break;
            }
        }
        ans+=( ((r*(r+1))/2) - ((l*(l+1))/2) );
        printf("%lld\n", ans);
        return 0;
    } 
