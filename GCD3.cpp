    #include<bits/stdc++.h>
    #include<stdio.h>
    #include<string.h>
    using namespace std;
    int main(){
    	int T, k;
    	long long pui;
    	char n[2005], m[2005];
    	scanf("%d", &T);
    	while(T--){
    		scanf("%s %s %d", n, m, &k);
    		// printf("pui\n");
    		int ind=strlen(n), count=0;
    		int len=min(k, ind);
    		sscanf(&n[ind-len], "%lld", &pui);
    		long long cur=(long long)pow(2, len);
    		for(int i=len;i>0;i--){
    			if(!(pui&(cur-1))){
    				count=i;
    				break;
    			}
    			cur>>=1;
    		}
     
    		count=min(count, k);
    		printf("%lld\n", (long long)pow(2, count));
    	}
    	return 0;
    } 
