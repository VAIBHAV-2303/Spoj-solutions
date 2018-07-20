    #include<stdio.h>
    #include<strings.h>
    #include<bits/stdc++.h>
    using namespace std;
    int dp[102][102];
    char a[102], b[102];
    int l1, l2;
    int fn(int i, int j){
    	if(i>=l1 || j>=l2){
    		dp[i][j]=0;
    		return dp[i][j];
    	}
    	if(dp[i][j]==-1){
    		if(a[i]==b[j]){
    			dp[i][j]=1+fn(i+1, j+1);
    		}
    		else{
    			dp[i][j]=max(fn(i, j+1), fn(i+1, j));
    		}
    	}
    	return dp[i][j];
    }
    int main(){
    	while(scanf("%s %s", a, b)!=EOF){
    		l1=strlen(a);
    		l2=strlen(b);
    		for(int i=0;i<102;i++){
    			for(int j=0;j<102;j++){
    				dp[i][j]=-1;
    			}
    		}
    		dp[0][0]=fn(0, 0);
    		
    		vector<char> lcs;
    		vector<char> ans;
    		int i=0, j=0;
     
    		while(lcs.size()!=dp[0][0]){
    			if(a[i]==b[j]){
    				lcs.push_back(a[i]);
    				i++;
    				j++;
    			}
    			else{
    				if(dp[i+1][j]>dp[i][j+1]){
    					i++;
    				}
    				else{
    					j++;
    				}
    			}
    		}
    		// printf("pui\n");
    		i=0;j=0;
    		for(int k=0;k<lcs.size();k++){
    			while(a[i]!=lcs[k] && i<l1){
    				ans.push_back(a[i]);
    				i++;
    			}
    			i++;
    			while(b[j]!=lcs[k] && j<l2){
    				ans.push_back(b[j]);
    				j++;
    			}
    			j++;
    			ans.push_back(lcs[k]);
    		}
    		// printf("pui\n");
    		while(i<l1){
    			ans.push_back(a[i]);
    			i++;
    		}
    		while(j<l2){
    			ans.push_back(b[j]);
    			j++;
    		}
    		// printf("pui\n");
     
    		for(i=0;i<ans.size();i++){
    			printf("%c", ans[i]);
    		}
    		printf("\n");
     
    	}
    	return 0;
    } 
