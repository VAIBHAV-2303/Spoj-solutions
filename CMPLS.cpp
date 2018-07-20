    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<long long int> v;
    vector<long long int> dp[105];
    vector<long long int> pui;
    int check(int ind){
    	for(int i=0;i<v.size();i++){
    		dp[ind].push_back(v[i]);
    	}
    	
    	for(int i=1;i<v.size();i++){
    		if(v[i]!=v[i-1]){
    			return 0;
    		}
    	}
    	return 1;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		int n, r, g=0;
    		scanf("%d %d", &n, &r);
    		long long temp;
    		v.clear();
    		for(int i=0;i<n;i++){
    			scanf("%lld", &temp);
    			v.push_back(temp);
    			dp[i].clear();
    		}
     
    		while(1){
    			if(check(g)==1){
    				break;
    			}
    			else{
    				g++;
    				pui.clear();
    				for(int i=1;i<v.size();i++){
    					pui.push_back(v[i]-v[i-1]);
    				}
    				v.clear();
    				for(int i=0;i<pui.size();i++){
    					v.push_back(pui[i]);
    				}
    			}
    		}
     
    		while(r--){
    			dp[g].push_back(dp[g][dp[g].size()-1]);
    			for(int i=g-1;i>=0;i--){
    				dp[i].push_back(dp[i][dp[i].size()-1] + dp[i+1][dp[i+1].size()-1]);
    			}
    		}
     
    		for(int i=n;i<dp[0].size();i++){
    			printf("%lld ", dp[0][i]);
    		}
    		printf("\n");
     
    	}
    	return 0;
    } 
