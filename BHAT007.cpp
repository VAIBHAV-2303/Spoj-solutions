    #include<stdio.h>
    #include<string.h>
    char a[103], b[103], ans[2][203];
    int b1, b2;
    void add(int ind, int base){
    	int t=0, p1=strlen(a)-1, p2=strlen(b)-1, x, y, carry=0;
     
    	while(p1>=0 || p2>=0){
    		if(p1<0){
    			x=0;
    		}
    		else{
    			x=a[p1]-'0';
    		}
     
    		if(p2<0){
    			y=0;
    		}
    		else{
    			y=b[p2]-'0';
    		}
    		// printf("pui\n");
    		ans[ind][t]=(x+y+carry)%base + '0';
    		carry=(x+y+carry)/base;
    		t++;
    		p1--;
    		p2--;
    	}
    	ans[ind][t]='\0';
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%s %s %d %d", a, b, &b1, &b2);
     
    		add(0, b1);
    		add(1, b2);
     
    		if(strcmp(ans[0], ans[1])){
    			printf("no\n");
    		}
    		else{
    			printf("yes\n");
    		}
    	}
    	return 0;
    } 