    #include<bits/stdc++.h>
    using namespace std;
    int arr[10000007];
    set<int> S;
    int main(){
     
    	for(long long int i=2;i<10000007;i++){
    		if(arr[i] == 0){
    			for(long long int j=i;j<10000007;j+=i){
    				arr[j]=i;
    			}	
    		}
    	}
     
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		S.clear();
     
    		int n, x, p;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &x);
    			while(x>1){
    				p=arr[x];
    				if(p==0){
    					p=x;
    				}
    				S.insert(p);
    				while(x%p==0){
    					x/=p;
    				}
    			}
    		}
     
    		for(int i=2;true;i++){
    			if(arr[i]==i && S.find(i)==S.end()){
    				printf("%d\n", i);
    				break;
    			}
    		}
    	}
        return 0;
    } 