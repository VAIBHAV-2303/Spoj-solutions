    #include<bits/stdc++.h>
    using namespace std;
    vector<pair<int, int> > a;
    pair<int, int> ans[100005];
    set<int> S;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		S.clear();
    		a.clear();
    		queue<int> q;
     
    		int n, realind, x, prev=-1;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &x);
    			a.push_back(make_pair(x, i));
    		}
     
    		sort(a.begin(), a.end());
     
    		// for(int i=0;i<n;i++){
    		// 	printf("%d ", a[i].first);
    		// }
    		// printf("\n");
    		// for(int i=0;i<n;i++){
    		// 	printf("%d ", a[i].second);
    		// }
    		// printf("\n");
     
    		set<int>:: iterator it;
    	
    		for(int i=n-1;i>=0;i--){
    			if(a[i].first!=prev){
    				while(!q.empty()){
    					S.insert(q.front());
    					q.pop();
    				}
    			}
    			if(S.empty()){
    				ans[a[i].second].first=-2;
    				ans[a[i].second].second=-2;
    			}
    			else{		
    				it=S.lower_bound(a[i].second);
    				if(it==S.end()){
    					ans[a[i].second].first=(*S.rbegin());
    					ans[a[i].second].second=(*S.begin());
    				}
    				else{
    					if(it==S.begin()){
    						ans[a[i].second].second=(*it);
    						ans[a[i].second].first=(*S.rbegin());
    					}
    					else{
    						ans[a[i].second].second=(*it);
    						it--;
    						ans[a[i].second].first=(*it);
    					}
    				}
    			}	
    			q.push(a[i].second);
    			prev=a[i].first;
    		}
     
    		for(int i=0;i<n;i++){
    			printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    		}	
    	}
    	return 0;
    } 