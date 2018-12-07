    #include<bits/stdc++.h>
    using namespace std;
    int main(){
            float n, p, q;
            int t=0;
            while(scanf("%f %f %f", &n, &p, &q)!=EOF){
            	t++;
            	printf("Case %d: %0.4f\n", t, (q+1.0)/(p+2.0));
            }
            return 0;
    }   