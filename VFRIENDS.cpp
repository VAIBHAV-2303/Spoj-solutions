    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    int v[100005], n;
    long long csum[100005];
    int bs(int i){
    	int l=i+1, r=n, mid;
    	while(r>=l){
    		mid=(l+r)/2;
    		if(r==l){
    			return l;
    		}
     
    		if(r-l==1){
    			if(v[r]>=i){
    				return r;
    			}
    			else{
    				return l;
    			}
    		}
     
    		if(v[mid]<i){
    			r=mid-1;
    		}
    		else{
    			l=mid;
    		}
    	}
     
    }
    int main(){
      int T;
      scanf("%d", &T);
      while(T--){
        int ind, flag=0, temp;
        scanf("%d", &n);
        for(int i=n;i>=1;i--){
            scanf("%d", &v[i]);
        }
     
        csum[0]=0;
        for(int i=1;i<=n;i++){
        	csum[i]=v[i]+csum[i-1];
        }
     
        if(csum[n]%2==1 || csum[n]>n*(n-1)){
            printf("SAD\n");
            continue;
        }
     
        for(int i=1;i<n;i++){
        	if(i>=v[i+1]){
        		if(csum[i]>(i*(i-1) + csum[n]-csum[i])){
        			flag=1;
        			printf("SAD\n");
        			break;
        		}
        	}
        	else if(i<=v[n]){
        		if(csum[i]>(i*(i-1) + i*(n-i))){
        			printf("SAD\n");
        			flag=1;
        			break;
        		}
        	}
        	else{
        		ind=bs(i);
        		if(csum[i]> (i*(i-1) + csum[n]-csum[ind] + i*(ind-i)) ){
        			printf("SAD\n");
        			flag=1;
        			break;
        		}
        	}
        }
        if(flag==0){
        	printf("HAPPY\n");
        }
     
      }
      return 0;
    } 
