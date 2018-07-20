    #include<stdio.h>
    #include<iostream>
    #include<bits/stdc++.h>
    #include<string>
    using namespace std;
    vector<pair<string, long long > >v1;
    vector<long long> v;
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int n, k;
    	string st;
    	long long temp, ans=0;
    	cin >> n >> k;
    	while(n--){
    		cin >> st;
    		cin >> temp;
    		v1.push_back(make_pair(st, temp));
    	}
    	
    	sort(v1.begin(), v1.end());
    	int j=0;
    	while(j<v1.size()){
    		temp=v1[j].second;
    		while(v1[j+1].first.compare(v1[j].first)==0){
    			temp+=v1[j+1].second;
    			j++;
    		}
    		v.push_back(temp);
    		j++;
    	}
     
    	sort(v.begin(), v.end(), greater<long long>());
    	n=v.size();
    	for(int i=0;i<min(k, n);i++){
    		// printf("%lld\n", v[i]);
    		ans+=v[i];
    	}
    	printf("%lld\n", ans);
    	return 0;
    } 
