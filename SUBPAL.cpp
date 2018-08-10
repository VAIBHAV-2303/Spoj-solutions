    #include<stdio.h>
    #include<string.h>
    #include<bits/stdc++.h>
    using namespace std;
    int T, freq[100005][26];
    char a[100005];
     
    int main(){
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		scanf("%s", a);
    		int n=strlen(a), odd, even, flag=0;
    		for(int i=0;i<100005;i++){
    			for(int j=0;j<26;j++){
    				freq[i][j]=0;
    			}
    		}
     
    		for(int i=1;i<=n;i++){
    			freq[i][a[i-1]-'a']++;
    			for(int j=0;j<26;j++){
    				freq[i][j]+=freq[i-1][j];
    			}
    		}
    		for(int i=n;i>0;i--){
    			for(int j=0;j<=n-i;j++){
    				odd=0;
    				even=0;
    				for(int u=0;u<26;u++){
    					if((freq[j+i][u]-freq[j][u])%2){
    						odd++;
    					}
    					else{
    						even++;
    					}
    				}
    				if(odd<=1){
    					printf("Case %d: %d\n", t, i);
    					flag=1;
    					break;
    				}
    			}
    			if(flag){
    				break;
    			}
    		}
     
    	}
    	return 0;
    } 
