    #include<stdio.h>
    #include<string.h>
    int main(){
    	int T, n, flag, count;
    	scanf("%d\n", &T);
    	char a[105], pui[2];
    	while(T--){
    		scanf("%[^\n]%*c", a);
    		// printf("pui->%s\n", a);
    		char* token = strtok(a, " |$ *@.&\\\"!^,?");
    		count=0;
    		while(token!=NULL){
    			flag=0;
    			for(int i=0;token[i]!='\0';i++){
    				if(token[i]=='#'){
    					flag=1;
    					break;
    				}
    			}
     
    			if(flag){
    				count++;
    				printf("%s\n", token);
    			}
    			token=strtok(NULL, " |$ *@.&\\\"!^,?");
    		}
    		if(count==0){
    			printf("No keywords.\n");
    		}
    	}
    	return 0;
    } 