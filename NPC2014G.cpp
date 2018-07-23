#include<stdio.h>
long long int m=1e9+7;
long long int a[32]={0};
long long int nc2(long long int x){
	return ((x*(x-1))/2)%m;
}
int main(){
	int n;
	scanf("%d", &n);
	long long x, cur, ans=0;
	while(n--){
		scanf("%lld", &x);
		for(int j=0;j<32;j++){
			if(x&1){
				a[j]++;
			}
			x>>=1;
		}
	}
	cur=1;
	for(int i=0;i<32;i++){
		ans=(ans+ ((cur*(nc2(a[i])))%m) )%m;
		cur=(cur*2)%m;
	}
	printf("%lld\n", ans);

}
