    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int dp[30005];
    vector<int> factors;
    int seg[120005];
    int m, k;
    int search(int l, int r, int s, int e, int ind){
        // printf("%d %d %d %d\n", l, r, s, e);
        if(l<=s&&r>=e){
            // printf("pui\n");
            return seg[ind];
        }
        if(l>(s+e)/2){
            return search(l, r, (s+e)/2+1, e, 2*ind+1);
        }
        if(r<=(s+e)/2){
            return search(l, r, s, (s+e)/2, 2*ind);
        }
        else{
            return (1LL*search(l, (s+e)/2, s, (s+e)/2, 2*ind)*search((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1))%m;
        }
    }
    int npr(int n, int r){
        if(r<0 || r>n){
            return 0;
        }
        if(n-r == n){
            return 1%m;
        }
        return search(n-r+1, n, 0, 30004, 1);
    }
    int fn(int n){
        if(n<0){
            return 0;
        }
        if(dp[n]==-1){
            // printf("%d\n", n);
            if(n==1 || n==0){
                dp[n]=1%m;
            }
            else{
                int partial=0;
                for(int i=0;i<factors.size() && factors[i]<=n;i++){
                    partial=(partial+ ((1LL*npr(n-1, factors[i]-1)*fn(n-factors[i]))%m) )%m;
                }
                dp[n]=partial;
            }
        }
        return dp[n];
    }
    int create(int l, int r, int ind){
        if(l==r){
            return l%m;
        }
        seg[2*ind]=create(l, (l+r)/2, 2*ind);
        seg[2*ind+1]=create(((l+r)/2)+1, r, 2*ind+1);
        return (1LL*seg[2*ind]*seg[2*ind+1])%m;
    }
    int main(){
        int n;
        scanf("%d %d %d", &n, &k, &m);
        for(int i=0;i<30004;i++){
            dp[i]=-1;
        }
        seg[1]=create(0, 30004, 1);
        for(int i=1;i*i<=k;i++){
            if(k%i==0){
                if(i*i==k){
                    factors.push_back(i);
                }
                else{
                    factors.push_back(i);
                    factors.push_back(k/i);
                }
            }
        }
        sort(factors.begin(), factors.end());
        printf("%d\n", fn(n));
        return 0;
    } 
