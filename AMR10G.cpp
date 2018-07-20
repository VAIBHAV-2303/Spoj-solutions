    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long a[20004];
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            int n, k;
            long long curr=100000000000000;
            scanf("%d %d", &n, &k);
     
            for(int i=0;i<n;i++){
                scanf("%lld", &a[i]);
            }   
            sort(a, a+n);
     
            for(int i=0;i<n-k+1;i++){
                curr=min(curr, a[i+k-1]-a[i]);
            }
            printf("%lld\n", curr);
        }
    } 
