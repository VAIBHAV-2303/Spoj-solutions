    #pragma GCC optimize ("O3")
    #include<bits/stdc++.h>
    using namespace std;
    int a[1003], b[1003], n, cnt;
    void rec(int l, int r, int op){
    	if(op==1){
    		int curmin=1e9;
    		for(int i=l;i<=r;i++){
    			curmin=min(curmin, b[i]-a[i]);
    		}
    		for(int i=l;i<=r;i++){
    			a[i]+=curmin;
    		}
    		cnt+=curmin;
    	}
    	else if(op==-1){
    		int curmin=1e9;
    		for(int i=l;i<=r;i++){
    			curmin=min(curmin, abs(b[i]-a[i]));
    		}
    		for(int i=l;i<=r;i++){
    			a[i]-=curmin;
    		}
    		cnt+=curmin;
    	}
    	
    	int j;
    	for(int i=l;i<=r;i++){
    		if(b[i]-a[i]>0){
    			j=i;
    			while(j<n && b[j]-a[j]>0){
    				j++;
    			}
    			j--;
    			rec(i, j, 1);
    			i=j;
    		}	
    		else if(b[i]-a[i]<0){
    			j=i;
    			while(j<n && b[j]-a[j]<0){
    				j++;
    			}
    			j--;
    			rec(i, j, -1);
    			i=j;
    		}
    	}
    }
    int main(){
    	cnt=0;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i]);
    	}
    	for(int i=0;i<n;i++){
    		scanf("%d", &b[i]);
    	}
     
    	rec(0, n-1, 0);
    	printf("%d\n", cnt);
    	return 0;
    } 