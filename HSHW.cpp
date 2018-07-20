    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> a;
    int main(){
    	int T;
    	scanf("%d", &T);
    	for(int t=1;t<=T;t++){
    		a.clear();
     
    		int n, temp, pos=0, neg=0;
    		scanf("%d", &n);
    		for(int i=0;i<n;i++){
    			scanf("%d", &temp);
    			if(temp>0){
    				pos++;
    			}
    			else{
    				neg++;
    			}
    			a.push_back(temp);
    		}
    		printf("Case %d:\n", t);
    		sort(a.begin(), a.end());
    		if(neg==0){
    			printf("%d %d\n", a[n-2], a[n-1]);
    			printf("%d %d\n", a[0], a[1]);
    			printf("%d %d\n", a[n-1], a[0]);
    			printf("%d %d\n", a[0], a[n-1]);
    		}
    		else if(pos==0){
    			printf("%d %d\n", a[0], a[1]);
    			printf("%d %d\n", a[n-2], a[n-1]);
    			printf("%d %d\n", a[0], a[n-1]);
    			printf("%d %d\n", a[n-1], a[0]);
    		}
    		else if(pos==1 && neg==1){
    			printf("%d %d\n", a[0], a[1]);
    			printf("%d %d\n", a[0], a[1]);
    			if(abs(a[1])>abs(a[0])){
    				printf("%d %d\n", a[0], a[1]);
    				printf("%d %d\n", a[1], a[0]);
    			}
    			else if(abs(a[1])<abs(a[0])){
    				printf("%d %d\n", a[1], a[0]);
    				printf("%d %d\n", a[0], a[1]);
    			}
    			else{
    				printf("%d %d\n", a[0], a[1]);
    				printf("%d %d\n", a[0], a[1]);
    			}
    		}
    		else if(pos==1){
    			printf("%d %d\n", a[0], a[1]);
    			printf("%d %d\n", a[0], a[n-1]);
    			printf("%d %d\n", a[0], a[n-2]);
    			if((float)((1.0*a[n-1])/a[n-2])>(float)((1.0*a[0])/a[n-1])){
    				printf("%d %d\n", a[0], a[n-1]);
    			}
    			else if((float)((1.0*a[n-1])/a[n-2])<(float)((1.0*a[0])/a[n-1])){
    				printf("%d %d\n", a[n-1], a[n-2]);
    			}
    			else{
    				printf("%d %d\n", a[0], a[n-1]);
    			}
    		}
    		else if(neg==1){
    			// printf("pui\n");
    			printf("%d %d\n", a[n-2], a[n-1]);
    			printf("%d %d\n", a[0], a[n-1]);
    			printf("%d %d\n", a[n-1], a[1]);
    			if((float)((1.0*a[0])/a[1])>(float)((1.0*a[n-1])/a[0])){
    				printf("%d %d\n", a[n-1], a[0]);
    			}
    			else if((float)((1.0*a[0])/a[1])<(float)((1.0*a[n-1])/a[0])){
    				printf("%d %d\n", a[0], a[1]);
    			}
    			else{
    				printf("%d %d\n", a[0], a[1]);
    			}	
    		}
    		else{
    			int ind;
    			for(int i=0;i<n;i++){
    				if(a[i]>0){
    					ind=i;
    					break;
    				}
    			}
    			if(a[n-2]*a[n-1]>a[0]*a[1]){
    				printf("%d %d\n", a[n-2], a[n-1]);
    			}
    			else{
    				printf("%d %d\n", a[0], a[1]);
    			}
     
    			printf("%d %d\n", a[0], a[n-1]);
     
    			if((float)((1.0*a[n-1])/a[ind])>(float)((1.0*a[0])/a[ind-1])){
    				printf("%d %d\n", a[n-1], a[ind]);
    			}
    			else if((float)((1.0*a[n-1])/a[ind])<(float)((1.0*a[0])/a[ind-1])){
    				printf("%d %d\n", a[0], a[ind-1]);
    			}
    			else{
    				printf("%d %d\n", a[0], a[ind-1]);
    			}
     
    			if((float)((1.0*a[0])/a[ind])>(float)((1.0*a[n-1])/a[ind-1])){
    				printf("%d %d\n", a[n-1], a[ind-1]);
    			}
    			else if((float)((1.0*a[0])/a[ind])<(float)((1.0*a[n-1])/a[ind-1])){
    				printf("%d %d\n", a[0], a[ind]);
    			}
    			else{
    				printf("%d %d\n", a[0], a[ind]);
    			}
    			
    		}
    	}
    	return 0;
    } 
