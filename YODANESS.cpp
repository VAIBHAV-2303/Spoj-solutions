    #include<stdio.h>
    #include<bits/stdc++.h>
    #include<iostream>
    using namespace std;
    map<string, int> mp;
    string a[30005];
    int b[30005], L[30005], R[30005];
    long long ans;
    void merge(int l, int mid, int r){
    	for(int i=0;i<(mid-l+1);i++){
    		L[i]=b[l+i];
    	}
    	for(int i=0;i<(r-mid);i++){
    		R[i]=b[mid+1+i];
    	}
    	int i=0, j=0, k=l;
    	while((i<(mid-l+1))&&(j<(r-mid))){
    		if(L[i]<=R[j]){
    			b[k]=L[i];
    			k++;
    			i++;
    		}
    		else{
    			ans+=mid-l+1-i;
    			b[k]=R[j];
    			k++;
    			j++;
    		}	
    	}
    	while(j<(r-mid)){
    		b[k]=R[j];
    		j++;
    		k++;
    	}
    	while(i<(mid-l+1)){
    		b[k]=L[i];
    		i++;
    		k++;
    	}
    }
    void split(int l, int r){
    	if(r>l){
    		int mid=(l+(r-l)/2);
    		split(l, mid);
    		split(mid+1, r);
    		merge(l, mid, r);
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		ans=0;
    		mp.clear();
    		int n;
    		string temp;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			cin >> a[i];
    		}
    		for(int i=1;i<=n;i++){
    			cin >> temp;
    			mp[temp]=i;
    		}
    		for(int i=0;i<n;i++){
    			b[i]=mp[a[i]];
    		}
    		split(0, n-1);
    		printf("%lld\n", ans);
    	}
    	return 0;
    } 
