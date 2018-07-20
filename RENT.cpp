    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long dp[10005];
    vector<pair<long long, pair<long long, long long> > >data;
    int n;
    long long fn(int ind, long long fin){
    	if(dp[ind]==-1){
    		long long max=0;
    		for(int i=ind+1;i<n;i++){
    			if(data[i].second.second>=fin){
    				if(data[i].second.first+fn(i, data[i].first)>max){
    					max=data[i].second.first+fn(i, data[i].first);
    				}
    			}
    		}
    		dp[ind]=max;
    	}
    	return dp[ind];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		data.clear();
    		long long start, duration, profit, max=-1, j;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			dp[i]=-1;
    		}
    		
    		for(int i=0;i<n;i++){
    			scanf("%lld %lld %lld", &start, &duration, &profit);
    			data.push_back(make_pair(start+duration, make_pair(profit, start)));
    		}
     
    		sort(data.begin(), data.end());
    		
    		for(int i=0;i<n;i++){
    			if(data[i].second.first+fn(i, data[i].first)>max){
    				max=data[i].second.first+fn(i, data[i].first);
    			}
    		}
     
    		printf("%lld\n", max);
     
    	}
    	return 0;
    } 
