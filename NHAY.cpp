    #include<iostream>
    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> jump;
    string p;
    string t;
    int main(){
    	int n;
    	ios_base :: sync_with_stdio(false);
    	cin.tie(NULL); 
    	while(cin >> n){
    		p.clear();
    		t.clear();
    		jump.clear();
    		cin >> p;
    		cin >> t;
    		int j=0;
    		jump.push_back(0);
    		for(int i=1;i<n;i++){
    			while(p[j]!=p[i] && j>0){
    				j=jump[j-1];
    			}
    			if(p[j]==p[i]){
    				j++;
    			}
    			jump.push_back(j);
    		}
     
    		// for(int i=0;i<n;i++){
    			// printf("%d ", jump[i]);
    		// }
    		// printf("\n");
     
    		int i=0, k=0, flag=0;
     
    		while(i<t.size()){
    			flag=0;
    			while(p[k]==t[i]){
    				i++;
    				k++;
    				flag=1;
    				if(k==n){
    					printf("%d\n", i-n);
    					break;
    				}
    			}
    			if(flag==1){
    				i--;
    			}
    			i++;
    			if(k>=1){
    				k=jump[k-1];
    			}
    			else{
    				k=0;
    			}
    		}
    	}
    	return 0;
    } 
