    #include<bits/stdc++.h>
    using namespace std;
    int m=1e9+7;
    char s1[105], s2[105];
    int main(){
       	int T;
       	scanf("%d", &T);
       	for(int t=1;t<=T;t++){
       		int ans=0, n, x;
       		scanf("%s", s1);
      		scanf("%s", s2);
       		n=strlen(s1);
       		x=1;
       		for(int i=n-1;i>=0;i--){
       			ans=(ans + ((1LL*x*((int)s2[i]-s1[i]) )%m) )%m;
       			x=(1LL*x*26ll)%m;
       		}      
       		printf("Case %d: %d\n", t, (ans-1+m)%m );
       	}
       	return 0;
    }  