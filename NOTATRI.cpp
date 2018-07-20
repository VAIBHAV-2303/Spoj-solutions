    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<long long > a;
    int bs1(long long x, int l){
    	int r=a.size(), mid;
    	r--;
    	while(r>=l){
    		mid=(l+r)/2;
    		if(r==l){
    			return l;
    		}
    		if(r-l==1){
    			if(a[l]>=x){
    				return l;
    			}
    			else{
    				return r;
    			}
    		}
    		if(a[mid]<x){
    			l=mid+1;
    		}
    		else{
    			r=mid;
    		}
    	}
    }
    int bs2(long long y, int l){
    	int r=a.size(), mid;
    	r--;
    	while(r>=l){
    		mid=(l+r)/2;
    		if(r==l){
    			return l;
    		}
    		if(r-l==1){
    			if(a[r]<=y){
    				return r;
    			}
    			else{
    				return l;
    			}
    		}
    		if(a[mid]>y){
    			r=mid-1;
    		}
    		else{
    			l=mid;
    		}
    	}
    }
    int main(){
    	while(1){
    		a.clear();
    		int n, l, r;
    		long long temp, ans=0;
    		scanf("%d", &n);
    		if(n==0){
    			break;
    		}
     
    		for(int i=0;i<n;i++){
    			scanf("%lld", &temp);
    			a.push_back(temp);
    		}
     
    		sort(a.begin(), a.end());
     
    		for(int i=0;i<=n-3;i++){
    			for(int j=i+1;j<=n-2;j++){
    				r=bs2(a[i]+a[j], j+1);
    				l=bs1(a[j]-a[i], j+1);
    				if(a[j]+a[i]>=a[a.size()-1] && (a[j]-a[i])<=a[j+1]){
    					continue;
    				}
    				if(a[i]+a[j]<a[j+1]){
    					ans+=n-1-j;
    					continue;
    				}
    				// printf("%d %d\n", i, j);
    				// printf("%d %d\n", l, r);
    				ans+=(n-j-1)-(r-l+1);
    			}
    		}
    		printf("%lld\n", ans);
    	}
    	return  0;
    } 
