    #include<stdio.h>
    int a[1000006]={0};
    int main(){
    	int u, q, n, l, r;
    	scanf("%d %d %d", &u, &q, &n);
    	while(u--){
    		scanf("%d %d", &l, &r);
    		a[l]++;
    		a[r+1]--;
    	}
    	for(int i=0;i<=n;i++){
    		a[i]+=a[i-1];
    	}
    	while(q--){
    		scanf("%d", &l);
    		printf("%d\n", a[l]);
    	}
    	return 0;
    } 
