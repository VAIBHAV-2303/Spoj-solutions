    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int a[200005], m=1e9+7, factarr[200005], BITree[200005];
    int getSum(int index){
        int sum=0;
        while(index>0){
            sum+=BITree[index];
            index-=index & (-index);
        }
        return sum;
    }
    void updateBIT(int n, int index){
        while(index<=n){
           BITree[index]++;
           index+=index & (-index);
        }
    }
    int main(){
    	factarr[0]=1;
    	for(int i=1;i<=200005;i++){
    		factarr[i]=(1LL*i*factarr[i-1])%m;
    	}
     
    	int T, curr;
    	scanf("%d", &T);
    	while(T--){
    		for(int i=0;i<=200005;i++){
    			BITree[i]=0;
    		}
     
    		int n, ans=1;
    		scanf("%d", &n);
    		for(int i=1;i<=n;i++){
    			scanf("%d", &a[i]);
    		}
     
    		for(int i=1;i<=n;i++){
    			curr=getSum(a[i]);
    			// printf("%d\n", curr);
    			ans=(ans+ ((1LL*(a[i]-curr-1)*factarr[n-i])%m) )%m;
    			updateBIT(n, a[i]);
    		}
    		printf("%d\n", ans);
    	}
    	return 0;
    } 
