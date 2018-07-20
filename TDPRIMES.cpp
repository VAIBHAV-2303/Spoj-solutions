    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<bool> arr (100000000, true);
    int main(){
    	arr[0]=false;
    	arr[1]=false;
    	for(long long i=2;i*i<100000000;i++){
    		if(arr[i] == true){
    			for(long long j=i;j*i<100000000;j++){
    				arr[j*i]=false;
    			}	
    		}
    	}
    	
    	printf("2\n");
    	int t=0;
    	for(long long i=3;i<100000000;i+=2){
    		if(arr[i]){
    			t++;
    			if(t%100==0){
    				printf("%lld\n", i);
    			}
    		}
    	}
     
    	return 0;
    } 
