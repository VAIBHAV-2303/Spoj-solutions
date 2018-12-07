    #include<bits/stdc++.h>
    using namespace std;
    int main(){
        int T;
        scanf("%d", &T);
        while(T--){
            int n;
            scanf("%d", &n);
            int tempn=n, req=0, x=1;
     
            while(tempn!=0){
            	req+=9*x;
            	tempn/=10;
            	x*=10;
            }
            
            req=abs(2*n-req);
            int flag=1;
            for(int i=2;i<=req;i++){
            	if(req%i==0){
            		flag=0;
            		printf("%d\n", i);
            		break;
            	}
            }
            if(flag){
            	printf("-1\n");
            }
        }
        return 0;
    } 