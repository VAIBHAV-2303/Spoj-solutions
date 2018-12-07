    #include<bits/stdc++.h>
    using namespace std;
    int T, ans, i, j;
    float ang, pui;
    int main(){
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		scanf("%f", &ang);
    		ans=0;
    		for(i=1;i<=12;i++){
    			for(j=0;j<=59;j++){
    				pui=abs( (30.0*i) - (5.5*j) );
    				if(pui>180){
    					pui-=180;
    				}
    				if(pui==ang){
    					ans++;
    				}
    			}
    		}
    		printf("Case %d: %d\n", t, ans);
    	}
    	return 0;
    } 