    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<long long int> sorted;
    int main(){
    	while(1){
    		long long n, temp, flag=1;
    		scanf("%lld", &n);
    		if(n==0){
    			break;
    		}
    		else{
    			sorted.clear();
    			stack<long long int> st1;
    			stack<long long int> st2;
    			for(long long i=0;i<n;i++){
    				scanf("%lld", &temp);
    				st2.push(temp);
    				sorted.push_back(temp);
    			}
    			for(long long i=0;i<n;i++){
    				temp=st2.top();
    				st2.pop();
    				st1.push(temp);
    			}
     
    			sort(sorted.begin(), sorted.end());
    			long long t=0;
    			while(t!=n){
    				if(sorted[t]!=t+1){
    					printf("no\n");
    					flag=0;
    					break;
    				}
    				if(!st2.empty() && st2.top()==sorted[t]){
    					st2.pop();
    					t++;
    				}
    				else{
    					if(st1.empty()){
    						printf("no\n");
    						// printf("%d\n", sorted[t]);
    						flag=0;
    						break;
    					}
    					while(st1.top()!=sorted[t]){
    						st2.push(st1.top());
    						st1.pop();
    						if(st1.empty()){
    							printf("no\n");
    							// printf("%d\n", sorted[t]);
    							flag=0;
    							break;
    						}
    					}
    					if(flag==0){
    						break;
    					}
    					st1.pop();
    					t++;
    				}
    			}
    			if(flag==1){
    				printf("yes\n");
    			}
    		}
    	}
    	return 0;
    } 
