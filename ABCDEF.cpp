    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<long long> va;
    vector<long long> vd;
    pair<vector<long long>:: iterator, vector<long long>:: iterator> it;
    int a[105];
    int main(){
    	int n;
    	long long ans=0;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    	}
     
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			for(int k=0;k<n;k++){
    				va.push_back(a[i]*a[j]+a[k]);
    				if(a[i]!=0){
    					vd.push_back(a[i]*(a[j]+a[k]));
    				}
    			}
    		}
    	}
     
    	sort(vd.begin(), vd.end());
     
    	for(int i=0;i<va.size();i++){
    		it=equal_range(vd.begin(), vd.end(), va[i]);
    		ans+=((it.second)-(it.first));
    	}
    	printf("%lld\n", ans);
     
    	return 0;
    } 
