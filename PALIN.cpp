    #include<stdio.h>
    #include<vector>
    #include<string.h>
    using namespace std;
    vector<int> a;
    char k[1000006];
    int check(){
    	int l=a.size();
    	for(int i=0;i<l/2;i++){
    		if(a[i]!=a[l-i-1]){
    			return 0;
    		}
    	}
    	return 1;
    }
    int main(){
    	long long int T;
    	scanf("%lld", &T);
    	while(T--){
    		scanf("%s", k);
    		int l=strlen(k), t;
    		// printf("%d\n", l);
    		a.clear();
    		for(int i=0;i<l;i++){
    			a.push_back((int)(k[l-1-i]-'0'));
    		}
    		a[0]++;
    		t=0;
    		while(a[t]==10){
    			a[t]=0;
    			t++;
    			if(t==l){
    				a.push_back(1);
    				l++;
    				break;
    			}
    			else{
    				a[t]++;
    			}
    		}
     
    		// for(int i=0;i<l;i++){
    			// printf("%d", a[l-i-1]);
    		// }
    		// printf("\n");
     
    		while(check()==0){
    			for(int i=0;i<l/2;i++){
    				if(a[i]<a[l-i-1]){
    					a[i]=a[l-i-1];
    				}
    				else if(a[i]>a[l-i-1]){
    					a[i]=a[l-i-1];
    					a[i+1]++;
    					t=i+1;
    					while(a[t]==10){
    						a[t]=0;
    						t++;
    						if(t==l){
    							a.push_back(1);
    							l++;
    							break;
    						}
    						else{
    							a[t]++;
    						}
    					}
    				}
    			}
    		}
     
     
     
    		for(int i=0;i<l;i++){
    			printf("%d", a[l-i-1]);
    		}
    		printf("\n");
     
    	}
    	return 0;
    } 
