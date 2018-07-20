    #include<bits/stdc++.h>
    #include<stdio.h>
    using namespace std;
    typedef struct Node{
    	int in;
    	int out;
    }node;
    typedef struct Adj{
    	int ver;
    	int vis;
    }adj;
    vector<adj> G[26];
    node a[26];
    string temp;
    void dfs(int ver){
    	for(int i=0;i<G[ver].size();i++){
    		if(G[ver][i].vis==0){
    			G[ver][i].vis=1;
    			dfs(G[ver][i].ver);
    		}
    	}
    }
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int T;
    	cin >> T;
    	while(T--){
    		for(int i=0;i<26;i++){
    			G[i].clear();
    		}
    		for(int i=0;i<26;i++){
    			a[i].in=0;
    			a[i].out=0;
    		}
    		int n, dhui;
    		cin >> n;
    		adj chui;
    		chui.vis=0;
    		for(int i=0;i<n;i++){
    			cin >> temp;
    			dhui=temp[0]-'a';
    			a[temp[0]-'a'].out++;
    			a[temp[temp.size()-1]-'a'].in++;
    			chui.ver=temp[temp.size()-1]-'a';
    			G[temp[0]-'a'].push_back(chui);
    		}
     
    		int od=0, ev=0, eq=0, st, en, flag=0;
     
    		for(int i=0;i<26;i++){
    			if(a[i].in==a[i].out){
    				eq++;
    			}
    			else if(a[i].in+1==a[i].out){
    				st=i;
    				od++;
    			}
    			else if(a[i].out+1==a[i].in){
    				ev++;
    				en=i;
    			}
    			else{
    				flag=1;
    				break;
    			}
    		}
     
    		if(flag){
    			cout << "The door cannot be opened." << "\n";
    			continue;
    		}
     
    		flag=0;
    		if(ev==1 && od==1){
    			chui.ver=st;
    			G[en].push_back(chui);
    		}
     
    		if((ev==0 && od==0) || (ev==1 && od==1)){
    			dfs(dhui);
    			for(int i=0;i<26;i++){
    				for(int j=0;j<G[i].size();j++){
    					if(G[i][j].vis==0){
    						cout << "The door cannot be opened." << "\n";	
    						flag=1;
    						break;
    					}
    				}
    				if(flag){
    					break;
    				}
    			}
    			if(flag==0){
    				cout << "Ordering is possible." << "\n";
    			}
    		}
    		else{
    			cout << "The door cannot be opened." << "\n";
    		}
     
    	}
    	return 0;
    } 
