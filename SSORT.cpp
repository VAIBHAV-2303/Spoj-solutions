    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    pair<int, int> b[100005];
    int main(){
    	int n, sm;
    	for(int t=1;true;t++){
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
    		int temp;	
    		long long ans=0, cycle;
    		for(int i=0;i<n;i++){
    			scanf("%d", &b[i].first);
    			b[i].second=i;
    		}
     
    		sort(b, b+n);
    		sm=b[0].first;
     
    		for(int i=0;i<n;i++){
    			cycle=0;
    			if(b[i].second!=i){
    				while(b[i].second!=i){
    					cycle++;
    					ans+=b[b[i].second].first+b[i].first;
    					temp=b[b[i].second].second;
    					b[b[i].second].second=b[i].second;
    					b[i].second=temp;
    				}
    				ans=min(ans, ans-(b[i].first*cycle)+(sm*cycle)+2*(b[i].first+sm));
    			}
    		}
    		printf("Case %d: %lld\n", t, ans);
    	}
    	return 0;
    } 
