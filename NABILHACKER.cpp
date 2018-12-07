    #include<bits/stdc++.h>
    using namespace std;
    char a[1000006];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		list<char> l;
    		list<char>:: iterator it=l.begin(), pui;
    		scanf("%s", a);
     
    		for(int i=0;a[i]!='\0';i++){
    			if(a[i]=='-'){
    				pui=it;
    				it--;
    				if(it!=l.end()){
    					l.erase(it);
    					it=pui;
    				}
    				else{
    					it++;
    				}
    			}
    			else if(a[i]=='<'){
    				if(it!=l.begin()){
    					it--;
    				}
    			}
    			else if(a[i]=='>'){
    				if(it!=l.end()){
    					it++;
    				}
    			}
    			else{
    				if(it==l.end()){
    					l.push_back(a[i]);
    				}
    				else{
    					l.insert(it, a[i]);
    				}	
    			}
    		}
     
    		for(it=l.begin();it!=l.end();it++){
    			printf("%c", (*it));
    		}
    		printf("\n");
    	}
    	return 0;
    } 