    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> a;
    set<int> S;
    set<int> ansset;
    set<int>:: iterator it;
    int main(){
    	int n, m, temp, ans=0;
    	scanf("%d", &n);
    	while(n--){
    		scanf("%d", &temp);
    		S.insert(temp);
    		scanf("%d", &m);
    		while(m--){
    			scanf("%d", &temp);
    			a.push_back(temp);
    		}
    	}
     
    	for(int i=0;i<a.size();i++){
    		it=S.find(a[i]);
    		if(it==S.end()){
    			it=ansset.find(a[i]);
    			if(it==ansset.end()){
    				ansset.insert(a[i]);
    				ans++;
    			}
    		}
    	}
     
    	printf("%d\n", ans);
     
    	return 0;
    } 
