    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		long long int a[4], total=0;
    		for(int i=0;i<4;i++){
    			scanf("%lld", &a[i]);
    			total+=a[i];
    		}
    		sort(a, a+4);
    		printf("Case %d: %lld\n", t, min(total/4, a[0]+a[1]+a[2]));
    	}
    	return 0;
    } 