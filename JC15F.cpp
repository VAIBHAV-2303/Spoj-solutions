    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    int m=1e9+7, factarr[1000006], a[1003];
    void generate(){
     
        factarr[0]=1;
        for(int i=1;i<1000006;i++){
            factarr[i]=(1LL*i*factarr[i-1])%m;
        }
     
        primes.push_back(2);
        int isprime;
        for(int i=3;i<1004;i+=2){
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
    int isprime(int x){
        int pui=1;
        for(int j=0;primes[j]*primes[j]<=x;j++){
        	if(x%primes[j]==0){
        		pui=0;
        		break;
        	}
        }
        return pui;
    }
    int etf(int n){
        if(n==1){
                return 1;
        }
         
        int res=n, flag=0;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                if(i*i==n){
                    if(isprime(i)){
                        res=(res-(res/i));  
                        flag=1;
                    }
                }
                else{
                    if(isprime(i)){
                        flag=1;
                        res=(res-(res/i));
                    }
                    if(isprime(n/i)==1){
                        flag=1;
                        res=(res-(res/(n/i)));
                    }   
                }
            }
        }
        if(flag==0){
            return n-1;
        }
        return res;
    }
    int power(int x, int y){
        int res=1;
        while(y){
            if(y&1){
                res=(1LL*res*x)%m;
            }
            y>>=1;
            x=(1LL*x*x)%m;
        }
        return res;
    }
    int gcd(int a, int b){
        if(a==0){
            return b;
        }
        return gcd(b%a, a);
    }
    int fn(int n, int d, int k){
        int partial=etf(d);
        partial=(1LL*partial*factarr[n/d])%m;
        for(int i=0;i<k;i++){
            partial=(1LL*partial*power(factarr[a[i]/d], m-2))%m;
        }
        return partial;
    }
    int main(){
        generate();
     
        int k, n=0, gc; 
        scanf("%d", &k);
        for(int i=0;i<k;i++){
            scanf("%d", &a[i]);
            n+=a[i];
        }
     
        gc=a[0];
        for(int i=1;i<k;i++){
            gc=gcd(a[i], gc);
        }
     
        int ans=0;
        for(int i=1;i*i<=gc;i++){
            if(gc%i==0){
                if(i*i==gc){
                    ans=(ans+fn(n, i, k))%m;
                }
                else{
                    ans=(ans+fn(n, i, k))%m;
                    // printf("%d\n", ans);
                    ans=(ans+fn(n, (gc/i), k))%m;
                    // printf("%d\n", ans);
                }
            }
        }
     
        ans=(1LL*ans*power(n, m-2))%m;
        printf("%d\n", ans);
        return 0;
    }	   
