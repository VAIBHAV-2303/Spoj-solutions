    #include<stdio.h>
    using namespace std;
    #include<bits/stdc++.h>
    int m=1e9 + 7, p=0;
    char a[100005];
    int factarr[100005];
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
    int nCr(int n, int r){
        int num=factarr[n];
        num=(1LL*num*power(factarr[r], m-2))%m;
        return (1LL*num*power(factarr[n-r], m-2))%m;
    }
    pair<int, int> fn(){
        pair<int, int> pr1, pr2;
        if(a[p]=='0'){
            p+=1;
            return make_pair(1, 1);
        }
        else if(a[p]=='1'){
            p+=1;
            pr1 = fn();
            pr2 = fn();
            return make_pair(((1LL*pr1.first*pr2.first)%m), (pr1.second+pr2.second));
        }
        else{
            p+=1;
            pr1 = fn();
            pr2= fn();
            return make_pair( (1LL*nCr(pr1.second+pr2.second, pr1.second)* ((1LL*pr1.first*pr2.first)%m) %m) , pr1.second+pr2.second);
        }
    }
    int main(){
        factarr[0]=1;
        for(int i=1;i<100005;i++){
            factarr[i]=(1LL*factarr[i-1]*i)%m;
        }
        int T;
        scanf("%d", &T);
        while(T--){
            p=0;
            scanf("%s", a);
            printf("%d\n", fn().first);
        }
       return 0;
    } 
