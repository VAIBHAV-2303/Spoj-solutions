    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<pair<long long, pair<long long, int> > >v;
    long long ans[100005];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		v.clear();
    		int n;
    		long long x, y, currmin;
    		scanf("%d", &n);
     
    		for(int i=0;i<n;i++){
    			scanf("%lld %lld", &x, &y);
    			v.push_back(make_pair(x, make_pair(y, i)));
    		}
     
    		sort(v.begin(), v.end());
     
    		for(int i=0;i<n;i++){
    			currmin=1000000000000000000;
    			for(int j=i-1;j>=0;j--){
    				if(((v[i].first-v[j].first)*(v[i].first-v[j].first))>currmin){
    					break;
    				}
    				if((v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second.first-v[j].second.first)*(v[i].second.first-v[j].second.first) < currmin){
    					currmin=(v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second.first-v[j].second.first)*(v[i].second.first-v[j].second.first);
    				}
    			}
    			for(int j=i+1;j<n;j++){
    				if(((v[j].first-v[i].first)*(v[j].first-v[i].first))>currmin){
    					break;
    				}
    				if((v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second.first-v[j].second.first)*(v[i].second.first-v[j].second.first) < currmin){
    					currmin=(v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second.first-v[j].second.first)*(v[i].second.first-v[j].second.first);
    				}
    			}
    			ans[v[i].second.second]=currmin;
    		}
     
    		for(int i=0;i<n;i++){
    			printf("%lld\n", ans[i]);
    		}
    	}
    	return 0;
    } 
