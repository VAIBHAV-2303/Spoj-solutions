    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<pair<long long, long long> > a;
    int n;
    int fn(int ind){
    	int partial=1;
    	for(int i=ind+1;i<n;i++){
    		if(a[i].second<a[ind].first){
    			partial++;
    		}
    	}
    	return partial;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		a.clear();
    		int max=-1, pui;
    		long long temp1, temp2;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%lld %lld", &temp1, &temp2);
    			a.push_back(make_pair(temp2, temp1));
    		}
     
    		sort(a.begin(), a.end());
     
    		for(int i=0;i<a.size();i++){
    			pui=fn(i);
    			if(pui>max){
    				max=pui;
    			}
    		}
     
    		printf("%d\n", max);
    	}
    	return 0;
    } 
