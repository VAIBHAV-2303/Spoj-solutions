    #include<bits/stdc++.h>
    #include<stdio.h>
    #include<string.h>
    using namespace std;
    int main(){
    	long long int T, jump[500005];
    	char s[500005];
    	scanf("%lld", &T);
    	while(T--){
    		long long int k, n;
    		scanf("%s %lld", s, &k);
    		n=strlen(s);
    		jump[0]=0;
    		long long int j=0;
    		for(long long int i=1;i<n;i++){
    			while(j>0 && s[i]!=s[j]){
    				j=jump[j-1];
    			}
    			if(s[i]==s[j]){
    				j++;
    			}
    			jump[i]=j;
    		}
     
    		printf("%lld\n", n+(n-jump[n-1])*(k-1));
    	}
    	return 0;
    } 
