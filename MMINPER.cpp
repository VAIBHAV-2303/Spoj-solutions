    #include<bits/stdc++.h>
    using namespace std;
    long long int seg[200040];
    long long int fn(long long int l, long long int r, int ind){
        if(l==r){
            return 1;
        }
        seg[2*ind]=fn(l, (l+r)/2, 2*ind);
        seg[2*ind+1]=fn(((l+r)/2)+1, r, 2*ind+1);
        return seg[2*ind]+seg[2*ind+1];
    }
    long long Search(long long l, long long r, long long x, int ind){
        if(l==r){
            return l;
        }
        if(seg[2*ind]>=x){
            return Search(l, (l+r)/2, x, 2*ind);
        }
        else{
            return Search(((l+r)/2)+1, r, x-seg[2*ind], 2*ind+1);
        }
    }
    void update(long long l, long long r, long long x, int ind){
        if(l==r){
            seg[ind]=0;
            ind>>=1;
            while(ind!=0){
                seg[ind]=seg[2*ind]+seg[2*ind+1];
                ind>>=1;
            }
            return;
        }
        if(((l+r)/2)>=x){
            return update(l, (l+r)/2, x, 2*ind);
        }
        else{
            return update(((l+r)/2)+1, r, x, 2*ind+1);
        }
    }
    int main(){
        long long m, n, x;
        while(1){
            scanf("%lld %lld", &n, &m);
            if(n==-1){
                return 0;
            }
            seg[1]=fn(1, n, 1);
            for(long long int i=1;i<=n;i++){
                x=m-(((n-i)*(n-i-1))/2)+1;
                if(x>1){
                    printf("%lld ", Search(1, n, x, 1));
                    m-=(x-1);
                    update(1, n, Search(1, n, x, 1), 1);
                }
                else{
                    printf("%lld ", Search(1, n, 1, 1));
                    update(1, n, Search(1, n, 1 , 1), 1);
                }
            }
            printf("\n");
        }
    } 