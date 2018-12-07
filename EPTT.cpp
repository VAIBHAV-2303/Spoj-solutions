    #include<bits/stdc++.h>
    using namespace std;
    int a[1535]={0};
    void fn(int ind, int x, int iter){
    	// printf("%d\n", ind);
    	if(iter==4){
    		return;
    	}
    	if(a[ind+30]>=x){
    		a[ind+30]-=x;
    		fn(ind+30, x, iter+1);
    	}
    	else{
    		fn(ind+30, a[ind+30], iter+1);
    		a[ind+30]=0;
    	}
    }
    int main(){
    	int n, x;
     
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &x);
    		a[x]++;
    	}
    	int ans=0;
    	for(int i=0;i<1415;i++){
    		if(a[i]>0){
    			fn(i, a[i], 1);	
    			ans+=a[i];
    			a[i]=0;
    		}
    	}
     
    	printf("%d\n", ans);
     
    	return 0;
    } 