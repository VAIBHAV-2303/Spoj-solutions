    #include<bits/stdc++.h>
    using namespace std;
    int top[100005], down[100005];
    int main(){
     
    	int n, x, y;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d %d", &x, &y);
    		top[x]++;
    		down[y]++;
    	}
    	int curmin=1e9;
    	for(int i=0;i<100005;i++){
    		if(top[i]+down[i]>=ceil((float)n/2.0)){
    			// printf("%d %d\n", top[i], (int)ceil(n/2));
    			curmin=min(curmin, (int)ceil(((float)n/2.0))-top[i]);
    		}
    	}
    	if(curmin==1e9){
    		printf("Impossible\n");
    	}
    	else{
    		printf("%d\n", max(curmin, 0));
    	}
     
    	return 0;
    } 