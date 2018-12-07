    #include<bits/stdc++.h>
    using namespace std;
    int ans[100005];
    multiset<pair<int, int> > S;
    multiset<pair<int, int> >:: iterator it;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		S.clear();
    		for(int i=0;i<100005;i++){
    			ans[i]=-1;
    		}
     
    		int n, k, x;
    		scanf("%d %d", &n, &k);
    		for(int i=0;i<k;i++){
    			scanf("%d", &x);
    			S.insert(make_pair(x, i));
    		}
    		int firstempty=0, pos;
    		for(int i=0;i<=k;i++){
    			while(ans[firstempty]!=-1){
    				firstempty++;
    			}
     
    			it=S.lower_bound(make_pair(i+1, -1000000000));
    			it--;
    			if(it==S.end() || (*it).first!=i){
    				ans[firstempty]=i;
    				firstempty++;
    			}
    			else{
    				pos=(*it).second;
    				pos++;
    				if(pos<=firstempty){
    					ans[firstempty]=i;
    					firstempty++;
    				}
    				else{
    					ans[pos]=i;
    				}
    			}
    		}
     
    		// for(int i=0;i<=k;i++){
    			// printf("%d ", ans[i]);
    		// }
    		// printf("\n");
     
    		n-=k;
    		n--;
    		n=n%(k+1);
    		printf("%d\n", ans[n]);
    	}
    	return 0;
    } 