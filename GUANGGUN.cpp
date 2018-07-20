    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	unsigned long long n;
    	while(scanf("%llu", &n)!=EOF){
    		printf("%llu\n", 81*(n/9)+(n%9)*(n%9));
    	}
    	return 0;
    } 
