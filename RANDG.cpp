    #include<stdio.h>
    #include<string.h>
    int main(){
    	char a[55];
    	int n;
    	int r[55];
    	while(scanf("%s", a)!=EOF){
    		n=strlen(a);
     
    		if(a[0]=='R'){
    			r[0]=1;
    		}
    		else{
    			r[0]=0;
    		}
     
    		for(int i=1;i<n;i++){
    			if(a[i]=='R'){
    				r[i]=r[i-1]+1;
    			}
    			else{
    				r[i]=r[i-1];
    			}
    		}
     
    		int curmin=r[n-1];
     
    		for(int i=0;i<n;i++){
    			if(((i+1)-r[i]+r[n-1]-r[i])<curmin){
    				curmin=(i+1)-r[i]+r[n-1]-r[i];
    			}
    		}
    		printf("%d\n", curmin);
    	}
    	return 0;
    } 