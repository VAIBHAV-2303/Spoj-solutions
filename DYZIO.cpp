    #include<stdio.h>
    using namespace std;
    char a[20004];
    int n, ans,  maxdepth, currcuts, p;
    void rec(int height){
    	if(p>=n){
    		return;
    	}
     
    	if(a[p]=='0'){
    		if(height>maxdepth){
    			ans=currcuts;
    			maxdepth=height;
    		}
    		p++;
    		return;
    	}	
    	else{
    		p++;
    		currcuts++;
    		rec(height+1);
    		rec(height+1);
    		return;
    	}
     
    }
    int main(){
    	int T=10;
    	while(T--){
    		scanf("%d", &n);
    		scanf("%s", a);
    		maxdepth=0;
    		currcuts=0;
    		p=0;
    		rec(0);
    		printf("%d\n", ans);
    	}
    	return 0;
    } 
