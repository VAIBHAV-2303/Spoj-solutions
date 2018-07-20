    #include<stdio.h>
    #include<math.h>
    #include<bits/stdc++.h>
    using namespace std;
    char pui[4];
    long long fn(long long n, int s){
    	if(n==1){
    		return 1;
    	}
     
    	if(n%2==0){
    		if(s==2){
    			return 2*fn(n/2, 2) - 1;
    		}
    		else{
    			return 2*fn(n/2, 1);
    		}
    	}
    	else{
    		if(s==2){
    			return 2*fn((n+1)/2, 1) - 1;
    		}
    		else{
    			return 2*fn(n/2, 2);
    		}
    	}
     
    }
    int main(){
    	while(1){
    		scanf("%s", pui);
    		if(pui[0]=='0' && pui[1]=='0' && pui[3]=='0'){
    			break;
    		}
    		int t, o, z;
    		long long n;
    		t=pui[0]-'0';
    		o=pui[1]-'0';
    		z=pui[3]-'0';
     
     
    		n=(10*t+o)*pow(10, z);
     
    		printf("%lld\n", fn(n, 2));
     
    	}
    	return 0;
    } 
