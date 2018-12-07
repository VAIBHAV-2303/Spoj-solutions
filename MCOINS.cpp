    #include<bits/stdc++.h>
    using namespace std;
    int dp[1000006];
    int main(){
    	int k, l, flag1, flag2, flag3;
    	scanf("%d %d", &k, &l);
     
    	dp[0]=0;
    	dp[1]=1;
     
    	for(int i=2;i<=1000000;i++){
    		flag1=0, flag2=0, flag3=0;
    		if(i-k<0){
    			flag1=1;
    		}
    		else{
    			if(dp[i-k]==1){
    				flag1=1;
    			}
    		}
     
    		if(i-l<0){
    			flag2=1;
    		}
    		else{
    			if(dp[i-l]==1){
    				flag2=1;
    			}
    		}
    		if(dp[i-1]==1){
    			flag3=1;
    		}
     
    		if(flag2 && flag3 && flag1){
    			dp[i]=0;
    		}
    		else{
    			dp[i]=1;
    		}
    	}
     
    	// for(int i=1;i<=20;i++){
    	// 	printf("%d\n", dp[i]);
    	// }
     
    	int T, n;
    	scanf("%d", &T);
    	while(T--){
    		scanf("%d", &n);
    		if(dp[n]){
    			printf("A");
    		}
    		else{
    			printf("B");
    		}
    	}
    	return 0;
    } 