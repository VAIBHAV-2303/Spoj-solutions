    #include<bits/stdc++.h>
    using namespace std;
    int dp1[35][35], dp2[35][35], a[35];
    int fn1(int l, int r){
    	if(l>r){
    		return 0;
    	}
     
    	if(dp1[l][r]==-1){
    		if(l==r){
    			return a[l]; 
    		}
    		else{
    			dp1[l][r]=max(a[l]+max(fn1(l+1, r-1), fn1(l+2, r)), a[r]+max(fn1(l+1, r-1), fn1(l, r-2)));
    		}
    	}
    	return dp1[l][r];
    }
    int fn2(int l, int r){
    	if(l>r){
    		return 0;
    	}
     
    	if(dp2[l][r]==-1){
    		if(l==r){
    			return a[l]; 
    		}
    		else{
    			dp2[l][r]=max(a[l]+min(fn2(l+1, r-1), fn2(l+2, r)), a[r]+min(fn2(l+1, r-1), fn2(l, r-2)));
    		}
    	}
    	return dp2[l][r];
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		
    		for(int i=0;i<35;i++){
    			for(int j=0;j<35;j++){
    				dp1[i][j]=-1;
    				dp2[i][j]=-1;
    			}
    		}
     
    		int n;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		printf("%d %d\n", fn1(0, n-1), fn2(0, n-1));
     
    	}
    	return 0;
    } 