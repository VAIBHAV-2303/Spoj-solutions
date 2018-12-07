    #include<bits/stdc++.h>
    #include<iostream>
    using namespace std;
    set<pair<int, string> > S;
    map <string, int> M;
    int main(){
     
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
     
    	int n, ch, x;
    	string aux;
    	cin >> n;
    	for(int t=1;t<=n;t++){
    		cin >> ch;
    		if(ch==1){
    			cin >> aux;
    			cin >> x;
    			M[aux]=x;
    			S.insert(make_pair(x, aux));
    		}
    		else if(ch==2){
    			cin >> aux;
    			cin >> x;
    			S.erase(S.find(make_pair(M[aux], aux)));
    			M[aux]=x;
    			S.insert(make_pair(M[aux], aux));
    		}
    		else{
    			cin >> aux;
    			cout << (*S.begin()).second << " " << t << "\n";
    			S.erase(S.begin());
    		}
    	}
    	return 0;
    } 