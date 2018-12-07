    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            int x, y;
            scanf("%d %d", &x, &y);
            int ans=x*y + (100-x)*(100-y);
            printf("%0.2f%\n", (((float)ans)/100.00) );
        }
        return 0;
    } 