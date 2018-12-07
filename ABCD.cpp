    #pragma GCC optimize ("O3")
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int n;
    	char a[100005];
    	scanf("%d", &n);
    	scanf("%s", a);
    	char last;
    	pair<char, char> ans;
     
    	for(int i=0;i<2*n;i+=2){
    		int flag[4]={0};
    		flag[a[i]-'A']=1;
    		flag[a[i+1]-'A']=1;
    		for(int j=0;j<4;j++){
    			if(flag[j]==0){
    				ans.first=(char)('A'+j);
    				flag[j]=1;
    				break;
    			}
    		}
    		for(int j=0;j<4;j++){
    			if(flag[j]==0){
    				ans.second=(char)('A'+j);
    				flag[j]=1;
    				break;
    			}
    		}
    		if(i!=0 && ans.first==last){
    			last=ans.first;
    			ans.first=ans.second;
    			ans.second=last;
    		}
    		last=ans.second;
    		printf("%c%c", ans.first, ans.second);
    	}		
    	printf("\n");
    	return 0;
    } 