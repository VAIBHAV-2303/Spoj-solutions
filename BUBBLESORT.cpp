#include<stdio.h>
long long a[10004], L[10004], R[10004];
int ans;
void merge(int l, int mid, int r){
	int L[mid-l+1], R[r-mid];
	for(int i=0;i<(mid-l+1);i++){
		L[i]=a[l+i];
	}
	for(int i=0;i<(r-mid);i++){
		R[i]=a[mid+1+i];
	}
	int i=0, j=0, k=l;
	while((i<(mid-l+1))&&(j<(r-mid))){
		if(L[i]<=R[j]){
			a[k]=L[i];
			k++;
			i++;
		}
		else{
			ans+=(mid-l-i+1);
			a[k]=R[j];
			k++;
			j++;
		}	
	}
	while(j<(r-mid)){
		a[k]=R[j];
		j++;
		k++;
	}
	while(i<(mid-l+1)){
		a[k]=L[i];
		i++;
		k++;
	}
}
void split(int l, int r){
	if(r>l){
		int mid=(l+(r-l)/2);
		split(l, mid);
		split(mid+1, r);
		merge(l, mid, r);
	}
}
int main(){
	int T;
	scanf("%d", &T);
	for(int t=1;t<=T;t++){
		int n;
		ans=0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%lld", &a[i]);
		}
		split(0, (n-1));
		printf("Case %d: %d\n", t, ans%10000007);
	}
	return  0;
}