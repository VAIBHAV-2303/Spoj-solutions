    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long A, x, n;
    		scanf("%lld %lld", &x, &A);
    		n=A-x;
    		printf("%lld\n", (((A+1)*n) - max((long long)0, (n*(n-1)/2))));
    	}
    	return 0;
    } 

