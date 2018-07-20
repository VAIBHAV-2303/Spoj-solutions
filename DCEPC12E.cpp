    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long ans, na[105]={0}, nb[105]={0}, k;
    long long int A[105][105], B[105][105]; 
    int main(){
    	ans=0;
    	int n, q;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			scanf("%lld", &A[i][j]);
    		}
    	}
     
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			scanf("%lld", &B[i][j]);
    		}
    	}
     
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			for(int k=0;k<n;k++){
    				ans+=(A[i][k]*B[k][j]);
    			}
    		}
    	}
     
    	for(int i=0;i<n;i++){
    		na[i]=0;
    		for(int j=0;j<n;j++){
    			na[i]+=A[j][i];
    		}
    	}
     
    	for(int i=0;i<n;i++){
    		nb[i]=0;
    		for(int j=0;j<n;j++){
    			nb[i]+=B[i][j];
    		}
    	}
    	// printf("%lld\n", nb[1]);
     
    	scanf("%d", &q);
     
    	char f;
    	int l, r;
    	// printf("%lld\n", ans);
    	while(q--){
    		scanf("\n%c ", &f);
    		scanf("%d %d %lld", &l, &r, &k);
    		if(f=='A'){
    			ans+=(k-A[l][r])*nb[r];
    			// printf("%d\n", nb[r]);
    			na[r]-=A[l][r];
    			na[r]+=k;
    			A[l][r]=k;
    		}
    		else{
    			ans+=(k-B[l][r])*na[l];
    			nb[l]-=B[l][r];
    			nb[l]+=k;
    			B[l][r]=k;
    		}
    		printf("%lld\n", ans);
    	}
     
    	return 0;
    } 
