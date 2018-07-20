    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    set<pair <int, int> > s;
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		queue<pair<int, pair <int, int> > > q;
    		int a, b, c, x, y, flag=0, curr;
    		scanf("%d %d %d", &a, &b, &c);
    		s.clear();
    		if(b>a){
    			x=b;
    			b=a;
    			a=x;
    		}
     
    		q.push(make_pair(0, make_pair(0, 0)));
    		s.insert(make_pair(0, 0));
     
    		set<pair <int, int> > :: iterator it;
     
    		while(!q.empty()){
    			x=q.front().second.first;
    			y=q.front().second.second;
    			curr=q.front().first;
    			/*if(x==2 && y==8){
    				printf("%d %d %d\n", x, y, q.front().first);
    				flag=1;
    				break;
    			}*/
    			if(x==c || y==c){
    				printf("%d\n", curr);
    				flag=1;
    				break;
    			}
    			q.pop();
    			if(x==0){
    				it=s.find(make_pair(a, y));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(a, y)));
    					s.insert(make_pair(a, y));
    				}
    			}
    			if(y==0){
    				it=s.find(make_pair(x, b));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(x, b)));
    					s.insert(make_pair(x, b));
    				}
    			}
    			if(x!=0 && y==0){
    				if(x>=b){
    					it=s.find(make_pair(x-b, b));
    					if(it==s.end()){
    						q.push(make_pair(curr+1,  make_pair(x-b, b)));
    						s.insert(make_pair(x-b, b));
    					}
    				}
    				else{
    					it=s.find(make_pair(0, x));
    					if(it==s.end()){
    						q.push(make_pair(curr+1,  make_pair(0, x)));
    						s.insert(make_pair(0, x));
    					}
    				}
     
    				it=s.find(make_pair(x, b));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(x, b)));
    					s.insert(make_pair(x, b));
    				}
    			}
    			if(y!=0 && x==0){
    				it=s.find(make_pair(y, 0));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(y, 0)));
    					s.insert(make_pair(y, 0));
    				}
     
    				it=s.find(make_pair(a, y));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(a, y)));
    					s.insert(make_pair(a, y));
    				}
    			}
    			if(x!=0 && y!=0){
    				if(x+y>=a){
    					it=s.find(make_pair(a, x+y-a));
    					if(it==s.end()){
    						q.push(make_pair(curr+1,  make_pair(a, x+y-a)));
    						s.insert(make_pair(a, x+y-a));
    					}
    				}
    				else{
    					it=s.find(make_pair(x+y, 0));
    					if(it==s.end()){
    						q.push(make_pair(curr+1,  make_pair(x+y, 0)));
    						s.insert(make_pair(x+y, 0));
    					}
    				}
     
    				if(x+y>=b){
    					it=s.find(make_pair(x+y-b, b));
    					if(it==s.end()){
    						q.push(make_pair(curr+1,  make_pair(x+y-b, b)));
    						s.insert(make_pair(x+y-b, b));
    					}
    				}
    				else{
    					it=s.find(make_pair(0, x+y));
    					if(it==s.end()){
    						q.push(make_pair(curr+1,  make_pair(0, x+y)));
    						s.insert(make_pair(0, x+y));
    					}
    				}
     
    				it=s.find(make_pair(x, 0));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(x, 0)));
    					s.insert(make_pair(x, 0));
    				}
     
    				it=s.find(make_pair(0, y));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(0, y)));
    					s.insert(make_pair(0, y));
    				}
     
    				it=s.find(make_pair(x, b));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(x, b)));
    					s.insert(make_pair(x, b));
    				}
     
    				it=s.find(make_pair(a, y));
    				if(it==s.end()){
    					q.push(make_pair(curr+1,  make_pair(a, y)));
    					s.insert(make_pair(a, y));
    				}	
    			}
    		}
    		if(flag==0){
    			printf("-1\n");
    		}
     
    	}
    	return 0;
    } 
