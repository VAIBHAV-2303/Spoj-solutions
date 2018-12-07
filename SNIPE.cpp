        #include<bits/stdc++.h>
        using namespace std;
        set<pair<int, int> >X;
        set<pair<int, int> >:: reverse_iterator it;
        vector<pair<int, int> > v;
        int main(){
        	while(1){
         
        		X.clear();
         
        		int n, ans=0, x, y;
        		scanf("%d", &n);
        		if(n==0){
        			return 0;
        		}
         
        		for(int i=0;i<n;i++){
        			scanf("%d %d", &x, &y);
        			X.insert(make_pair(x, y));
        		}
         
        		while(!X.empty()){
        			ans++;
        			v.clear();
        			x=20000;
        			y=20000;
        			for(it=X.rbegin();it!=X.rend();it++){
        				if((*it).first<=x && (*it).second<=y){
        					x=(*it).first;
        					y=(*it).second;
        					v.push_back(make_pair(x, y));
        				}
        				// printf("%d %d\n", x, y);
        			}
        			// printf("pui\n");
        			for(int i=0;i<v.size();i++){
        				X.erase(X.find(v[i]));
        			}
        		}
        		printf("%d\n", ans);
        	}
        }  