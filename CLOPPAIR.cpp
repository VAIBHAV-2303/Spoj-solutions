    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    pair<long long, pair<long long, int> > a[50005];
    long long dist(long long x1, long long y1, long long x2, long long y2){
    	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    }
    int main(){
    	int n;
    	long long ans=100000000000000000;
    	int ind1, ind2;
    	scanf("%d", &n);
     
    	for(int i=0;i<n;i++){
    		scanf("%lld %lld", &a[i].first, &a[i].second.first);
    		a[i].second.second=i;
    	}
    	sort(a, a+n);
     
    	for(int i=0;i<n-1;i++){
    		for(int j=i+1;j<n;j++){
    			if((a[i].first-a[j].first)*(a[i].first-a[j].first)>ans){
    				break;
    			}
    			if(dist(a[i].first, a[i].second.first, a[j].first, a[j].second.first)<ans){
    				ind1=a[i].second.second;
    				ind2=a[j].second.second;
    				ans=dist(a[i].first, a[i].second.first, a[j].first, a[j].second.first);
    			}
    		}
    	}
    	printf("%d %d %.6f\n", min(ind1, ind2), max(ind1, ind2), sqrt(ans))	;
    	return 0;
    } 
