    #include<bits/stdc++.h>
    #include<string.h>
    using namespace std;
    int freq[100005]={0};
    int main(){
    	char a[100005];
    	scanf("%s", a);
     
    	int n = strlen(a);
    	int x;
     
    	for(int i=0;i<n;i++){
    		x=(int)(a[i]-'0');
    		freq[x]=1;
    	}
     
    	for(int i=0;i<n-1;i++){
    		x=10*(int)(a[i]-'0') + (int)(a[i+1]-'0');
    		freq[x]=1;
    	}			
     
    	for(int i=0;i<n-2;i++){
    		x=100*(int)(a[i]-'0') + 10*(int)(a[i+1]-'0') + (int)(a[i+2]-'0');
    		freq[x]=1;
    	}
     
    	for(int i=0;i<n-3;i++){
    		x=1000*(int)(a[i]-'0') + 100*(int)(a[i+1]-'0') + 10*(int)(a[i+2]-'0') + (int)(a[i+3]-'0');
    		freq[x]=1;
    	}
     
    	for(int i=0;i<n-4;i++){
    		x=10000*(int)(a[i]-'0') + 1000*(int)(a[i+1]-'0') + 100*(int)(a[i+2]-'0') + 10*(int)(a[i+3]-'0') + (int)(a[i+4]-'0');
    		freq[x]=1;
    	}
    	// printf("pui\n");
    	x = 0;
    	while(1){
    		if(freq[x]==0){
    			printf("%d\n", x);
    			break;
    		}
    		x++;
    	}
     
    	return 0;
    } 