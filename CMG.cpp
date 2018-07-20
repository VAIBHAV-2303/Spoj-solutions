    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){	
    		stack<int> st;
    		int q, x;
    		char ch;
    		scanf("%d", &q);
    		printf("Case %d:\n", t);
    		while(q--){
    			scanf("\n%c", &ch);
    			if(ch=='A'){
    				scanf("%d", &x);
    				if(st.empty()){
    					st.push(x);
    				}
    				else{
    					if(x>st.top()){
    						st.push(x);
    					}
    					else{
    						st.push(st.top());
    					}
    				}
    			}
    			else if(ch=='Q'){
    				if(st.empty()){
    					printf("Empty\n");
    				}
    				else{
    					printf("%d\n", st.top());
    				}
    			}
    			else if(ch=='R'){
    				if(!st.empty()){
    					st.pop();
    				}
    			}
    		}
    	}
    	return 0;
    } 
