    #include<stdio.h>
    #include<string.h>
    using namespace std;
    char a[2005];
    int main(){
    	for(int t=1;true;t++){
    		scanf("%s", a);
    		if(a[0]=='-'){
    			break;
    		}
    		int n=strlen(a), count=0, ans=0;
    		for(int i=0;i<n;i++){
    			if(a[i]=='{'){
    				count++;
    			}
    			if(a[i]=='}'){
    				count--;
    			}
     
    			if(count<0){
    				count+=2;
    				ans++;
    			}
    		}
    		ans+=(count/2);
    		printf("%d. %d\n", t, ans);
     
    	}
    	return 0;
    } 
