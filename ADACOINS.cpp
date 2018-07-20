    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    bitset<100005> bs;
    int csum[100005];
    int main(){
    	bs[0]=1;
    	int n, q, x, l, r;
    	scanf("%d %d", &n, &q);
    	for(int i=0;i<n;i++){
    		scanf("%d", &x);
    		bs|=bs<<x;
    	}
    	csum[0]=0;
    	for(int i=1;i<100005;i++){
    		csum[i]=csum[i-1]+bs[i];
    	}
     
    	while(q--){
    		scanf("%d %d", &l, &r);
    		printf("%d\n", csum[r]-csum[l-1]);
    	}
     
    	return 0;
    } 
