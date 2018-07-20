        #include<stdio.h>
        #include<bits/stdc++.h>
        using namespace std;
        vector<int> primes;
        vector<int> v;
        int arr[100005];
        int spfa[100005];
        void generate(){
            int isprime;
            primes.push_back(2);
            spfa[2]=2;
            for(int i=3;i<100005;i++){
                    isprime=1;
                    for(int j=0;primes[j]*primes[j]<=i;j++){
                            if(i%primes[j]==0){
                                    isprime=0;
                                    spfa[i]=primes[j];
                                    break;
                            }
                    }
                    if(isprime==1){
                            spfa[i]=i;
                            primes.push_back(i);
                    }
            }
        }
        int num(int n){
            int pui, temp;
            if(n==1){
                return 1;
            }
         
            v.clear();
            while(n!=1){
                    v.push_back(spfa[n]);
                    n=n/spfa[n];
            }
            pui=1;
            int i=0;
            while(i<v.size()){
                    temp=1;
                    while((i+1)<v.size() && v[i+1]==v[i]){
                            temp++;
                            i++;
                    }
                    pui*=(2*temp+1);
                    i++;
            }
            return pui;
        }
        unordered_map< int, vector<int> > store;
        int findFrequency(int left,int right, int element){
            int a=lower_bound(store[element].begin(),store[element].end(),left)-store[element].begin();
            int b=upper_bound(store[element].begin(),store[element].end(),right)-store[element].begin();
            return b-a;
        }
        int main(){
            generate();
            for(int i=1;i<100005;i++){
                arr[i]=num(i);
            }
            for(int i=1;i<100005;++i){
                store[arr[i]].push_back(i+1);  
            }
     
            int T, k, x;
            long long l, r;
            scanf("%d", &T);
            while(T--){
                scanf("%d %lld %lld", &k, &l, &r);
                x=(int)sqrt(l);
                if((long long)x*x<l){
                    x++;
                } 
                printf("%d\n", findFrequency(x+1, (int)sqrt(r)+1, k));
            }
            return 0;
        }  
