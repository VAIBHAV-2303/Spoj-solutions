    #include<bits/stdc++.h>
    using namespace std;
    map<int, int> mp;
    vector<int> x, y, a;
    int main(){
        int p;
        scanf("%d", &p);
     
        for(int i=1;i<=p-1;i++){
            mp[(1LL*i*i)%p]=i;
            // printf("%d\n", (1LL*i*i)%p);
            a.push_back((1LL*i*i)%p);
        }
     
        sort(a.begin(), a.end());
     
        x.push_back(1);
        int j=0;
        for(int i=1;i<a.size();i++){
            if(mp.find(p+1- ((1LL*x[j]*x[j])%p)) != mp.end()){
                y.push_back(mp[p+1- ((1LL*x[j]*x[j])%p)]);
                break;
            }
            
            if(mp.find(a[i]-((1LL*x[j]*x[j])%p)) !=mp.end()){
                y.push_back(mp[a[i]- ((1LL*x[j]*x[j])%p)]);
                x.push_back(mp[a[i]]);
                j++;
            }
        }
     
        printf("%d\n", x.size());
        for(int i=0;i<x.size();i++){
            printf("%d ", x[i]);
        }
        printf("\n");
        for(int i=0;i<x.size();i++){
            printf("%d ", y[i]);
        }
        printf("\n");
        return 0;
    } 