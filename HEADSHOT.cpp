    #include<stdio.h>
    #include<string.h>
    using namespace std;
    int main(){
    	char a[105];
    	scanf("%s", a);
    	int n=strlen(a), sh=0, rt=0;
     
    	for(int i=0;i<n-1;i++){
    		if(a[i]=='0'){
    			if(a[i+1]=='1'){
    				rt++;
    			}
    			else{
    				sh++;
    			}
    		}
    	}
    	if(a[n-1]=='0'){
    		if(a[0]=='1'){
    			rt++;
    		}
    		else{
    			sh++;
    		}
    	}
     
    	if(rt==0){
    		printf("EQUAL\n");
    		return 0;
    	}
     
    	if(rt>sh){
    		printf("ROTATE\n");
    	}
    	else if(sh>rt){
    		printf("SHOOT\n");
    	}
    	else{
    		printf("EQUAL\n");
    	}
     
    	return 0;
    } 
