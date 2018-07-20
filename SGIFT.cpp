    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<long long> a;
    vector<long long> cum;
    int bs1(long long x){
    	int l=0, r=a.size(), mid;
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
    int bs2(long long y){
    	int l=0, r=a.size(), mid;
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
    	int n, l, r;
    	long long temp, x, y;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%lld", &temp);
    		a.push_back(temp);
    	}
     
    	sort(a.begin(), a.end());
    	cum.push_back(a[0]);
    	for(int i=1;i<n;i++){
    		cum.push_back(a[i]+cum[i-1]);
    	}
    	int q;
    	scanf("%d", &q);
    	while(q--){
    		scanf("%lld %lld", &x, &y);
    		l=bs1(x);
    		r=bs2(y);
    		// printf("%d %d\n", l, r);
    		if(x>a[a.size()-1]){
    			printf("0\n");
    			continue;
    		}
    		if(y<a[0]){
    			printf("0\n");
    			continue;
    		}
    		if(l==0){
    			printf("%lld\n", cum[r]);
    		}
    		else{
    			printf("%lld\n", cum[r]-cum[l-1]);
    		}
    	}	
    	return 0;
    } 
