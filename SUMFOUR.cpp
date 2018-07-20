    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long a[2505], b[2505], c[2505], d[2505]; 
    vector<long long> ab, cd;
    pair<vector<long long>:: iterator, vector<long long>::iterator > ip;
    int main(){
    	int n;
    	scanf("%d", &n);
    	long long ans=0;
    	for(int i=0;i<n;i++){
    		scanf("%lld %lld %lld %lld", &a[i], &b[i], &c[i], &d[i]);
    	}
     
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			ab.push_back(a[i]+b[j]);
    		}
    	}
     
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			cd.push_back(-c[i]-d[j]);
    		}
    	}
     
    	sort(cd.begin(), cd.end());
    	// for(int i=0;i<cd.size();i++){
    		// printf("%lld ", cd[i]);
    	// }
    	// printf("\n");
    	for(int i=0;i<ab.size();i++){
    		// printf("ab->%lld\n", ab[i]);
    		ip=equal_range(cd.begin(), cd.end(), ab[i]);
    		ans+=((ip.second)-(ip.first))	;
    		// printf("%lld\n", ans);
    	}
    	printf("%lld\n", ans);
    	return 0;
    } 
