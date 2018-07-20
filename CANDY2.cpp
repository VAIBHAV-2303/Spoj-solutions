    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    pair<pair<long long, int>, pair<long long, long long> > a[5005];
    int main(){
    	int n, ansc, ansb, anss;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%lld %lld %lld", &a[i].first.first, &a[i].second.first, &a[i].second.second);
    		a[i].first.second=i;
    	}
    	sort(a, a+n, greater< pair<pair<long long, int>, pair<long long, long long> > >());
    	// for(int i=0;i<n;i++){
    		// printf("%lld %lld %lld\n", a[i].first.first, a[i].second.first, a[i].second.second);
    	// }
     
    	long long curmax=-1;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			if(i!=j){
    				if(i==0 || j==0){
    					if(j-i==1 || i-j==1){
    						if(a[2].first.first+a[i].second.first+a[j].second.second>curmax){
    							curmax=a[2].first.first+a[i].second.first+a[j].second.second;
    							ansc=a[2].first.second;
    							anss=a[i].first.second;
    							ansb=a[j].first.second;
    							// printf("%lld\n", curmax);
    						}
    					}
    					else{
    						if(a[1].first.first+a[i].second.first+a[j].second.second>curmax){
    							curmax=a[1].first.first+a[i].second.first+a[j].second.second;
    							ansc=a[1].first.second;
    							anss=a[i].first.second;
    							ansb=a[j].first.second;
    							// printf("%lld\n", curmax);	
    						}
    					}
    				}
    				else{
    					if(a[0].first.first+a[i].second.first+a[j].second.second>curmax){
    						curmax=a[0].first.first+a[i].second.first+a[j].second.second;
    						ansc=a[0].first.second;
    						anss=a[i].first.second;
    						ansb=a[j].first.second;
    						// printf("%lld\n", curmax);
    					}
    				}
    			}
    		}
    	}
    	// printf("%lld\n", curmax);
    	printf("%d\n%d\n%d\n", ansc, anss, ansb);
    	return 0;
    } 
