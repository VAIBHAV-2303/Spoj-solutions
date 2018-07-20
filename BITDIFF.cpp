    #include<bits/stdc++.h>
    #include<stdio.h>
    using namespace std;
    int arr1[32], arr0[32];
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		for(int i=0;i<32;i++){
    			arr1[i]=0;
    			arr0[i]=0;
    		}
     
    		int n;
    		long long curr, x, ans=0;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &curr);
    			x=1;
    			for(int j=0;j<32;j++){
    				if((x&curr) == x){
    					// printf("chui\n");
    					arr1[j]++;
    				}
    				else{
    					// printf("pui\n");
    					arr0[j]++;
    				}
    				x<<=1;
    			}
    		}
     
    		for(int i=0;i<32;i++){
    			ans=(ans + ((arr1[i]*arr0[i])%10000007))%10000007;
    		}
    		printf("Case %d: %lld\n", t, (2*ans)%10000007);
    	}
    	return 0;
    } 
