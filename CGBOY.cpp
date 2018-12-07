    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		float n, c;
    		scanf("%f %f", &n, &c);
    		printf("%0.2f\n", ((9.0-n)*4.00 + ((n-1.0)*c))/8.0);
    	}
    	return 0;
    } 