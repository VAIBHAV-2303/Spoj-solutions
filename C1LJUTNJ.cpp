    #include<stdio.h>
    #include<bits/stdc++.h>
    #define i64 long long
    template< class T > T _min(T a, T b) { return (a < b ? a : b); }
    using namespace std;
    int main(){
    	int n, m, a[100005], temp;
    	scanf("%d %d", &m, &n);
    	i64 tot=0, ans=0;
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    		tot+=a[i];
    	}
    	tot-=m;
    	sort(a, a+n);
     
    	for(int i=0;i<n;i++){
    		temp=min((i64)a[i], tot/(n-i));
    		ans+=(i64) temp*temp;
    		tot-=temp;
    	}
    	printf("%lld\n", ans);
    	return 0;
    } 
