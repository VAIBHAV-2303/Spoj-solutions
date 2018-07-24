#include<stdio.h>
using namespace std;
int a[100005], k;
int left(int ind){
	if(ind==0){
		return 1;
	}

	if(a[ind]==2){
		return 0;
	}

	if(a[ind]-a[ind-1]==1 || a[ind]-a[ind-1]==2){
		return left(ind-1);
	}
	return 0;
}
int right(int ind){
	if(ind==k-1){
		return 1;
	}

	if(a[ind]==2){
		return 0;
	}

	if(a[ind]-a[ind+1]==1 || a[ind]-a[ind+1]==2){
		return right(ind+1);
	}
	return 0;
}
int main(){
	int n;
	while(scanf("%d %d", &n, &k)!=EOF){
		int curmax=-1, maxind, ok=0;
		for(int i=0;i<k;i++){
			scanf("%d", &a[i]);
			if(a[i]>curmax){
				curmax=a[i];
				maxind=i;
			}
		}

		if(maxind==0){
			// printf("pui\n");
			ok=right(0);
		}
		else if(maxind==k-1){
			ok=left(k-1);
		}
		else{
			if(a[maxind]==2){
				printf("N\n");
				continue;
			}
			if((a[maxind-1]==a[maxind]-1 && a[maxind+1]==a[maxind]-2) || (a[maxind-1]==a[maxind]-2 && a[maxind+1]==a[maxind]-1)){
				if(left(maxind-1) && right(maxind+1)){
					ok=1;
				}
			}
		}

		if(ok){
			printf("S\n");
		}
		else{
			printf("N\n");
		}
	}
	return 0;
}
