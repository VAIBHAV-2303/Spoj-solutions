    #include<bits/stdc++.h>
    using namespace std;
    vector<long long> a;
    int main(){
     
    	a.push_back(1);
    	a.push_back(2);
     
    	for(int i=2;a[i-1]<=1e15;i++){
    		a.push_back(a[i-1]+a[i-2]);
    		// printf("%lld\n", a[i-1]+a[i-2]);
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		long long m, ans=0;
    		scanf("%lld", &m);
    		int ind;
    		while(m!=0){
    			ind=lower_bound(a.begin(), a.end(), m)-a.begin();
    			if(a[ind]==m){
    				ans+=a[ind+1];
    				m=0;
    			}
    			else{
    				ans+=a[ind];
    				m-=a[ind-1];
    			}
    		}
    		printf("%lld\n", ans);
    	}
    	return 0;
    } 