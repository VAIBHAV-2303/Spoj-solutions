    #include<bits/stdc++.h>
    using namespace std;
    char a[1000006][20];
    int mp[1000006], vis[1000006];
    int main(){
     
    	for(int i=0;i<1000006;i++){
    		vis[i]=-1;
    	}
     
    	int n, x;
    	long long m;
    	scanf("%d %lld", &n, &m);
     
    	for(int i=0;i<n;i++){
    		scanf("\n%[^\n]s", a[i]);
    		if(a[i][0]!='c' && a[i][0]!='g'){
    			x=0;
    			for(int j=0;a[i][j]!=':';j++){
    				x=10*x + ((int)(a[i][j]-'0'));
    			}
    			mp[x]=i+1;
    		}
    	}
     
    	int curline=0, lincr, incycle=0;
    	long long c=0;
    	while(1){
    		if(curline==n){
    			printf("WA\n");
    			return 0;
    		}
     
    		if(a[curline][0]=='c'){
    			lincr=curline;
    			c++;
    			curline++;
    		}
    		else if(a[curline][0]=='g'){
    			x=0;
    			for(int j=5;a[curline][j]!=';';j++){
    				x=10*x + ((int)(a[curline][j]-'0'));
    			}
    			if(vis[x]!=-1 && incycle==0){
    				if(c==vis[x]){
    					printf("TLE\n");
    					return 0;
    				}
    				else{
    					m-=c;
    					m=m%(c-vis[x]);
    					if(m==0){
    						printf("%d\n", lincr+1);
    						return 0;
    					}
    					c=0;
    				}
    				curline=mp[x];
    				incycle=1;
    			}
    			else{
    				vis[x]=c;
    				curline=mp[x];
    			}
    		}
    		else{
    			curline++;
    		}
     
    		if(c==m){
    			printf("%d\n", curline);
    			return 0;
    		}
    	}
    } 