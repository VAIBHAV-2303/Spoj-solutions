    #include<stdio.h>
    #include<string>
    #include<iostream>
    using namespace std;
    string s;
    long long dp[5005];	
    long long fn(int ind){
    	int l=s.size();
    	if(s[ind]=='0'){
    		return 0;
    	}
     
    	if(dp[ind]==-1){
    		if(ind<l-2){
    			if(s[ind]=='1' && s[ind+1]!='0'){
    				dp[ind]=fn(ind+1)+fn(ind+2);
    			}
    			else if(s[ind=='1'] && s[ind+1]=='0'){
    				dp[ind]=fn(ind+2);
    			}
    			else if( (s[ind]=='2' && s[ind+1]!=0) && s[ind+1]<='6'){
    				dp[ind]=fn(ind+1)+fn(ind+2);
    			}
    			else if(s[ind]=='2' && s[ind+1]=='0'){
    				dp[ind]=fn(ind+2);
    			}
    			else{
    				dp[ind]=fn(ind+1);
    			}
    		}
    		else{
    			if(ind==l-2){
    				if(s[ind]=='1' && s[ind+1]!='0'){
    					dp[ind]=2;
    				}
    				else if(s[ind=='1'] && s[ind+1]=='0'){
    					dp[ind]=1;
    				}
    				else if( (s[ind]=='2' && s[ind+1]!=0) && s[ind+1]<='6'){
    					dp[ind]=2;
    				}
    				else if(s[ind]=='2' && s[ind+1]=='0'){
    					dp[ind]=1;
    				}
    				else{
    					dp[ind]=fn(ind+1);
    				}		
    			}
    			else{
    				dp[ind]=1;
    			}
    		}
    	}
    	return dp[ind];
    }
    int main(){
    	while(1){
    		s.clear();
    		for(int i=0;i<5005;i++){
    			dp[i]=-1;
    		}
    		cin >> s;
    		if(s[0]=='0'){
    			break;
    		}
    		printf("%lld\n", fn(0));
    	}
    	return 0;
    } 
