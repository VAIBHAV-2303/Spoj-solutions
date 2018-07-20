    #include<stdio.h>
    #include<math.h>
    using namespace std;
    int main(){
    	int y, comp=0;
    	long long ind, currmax;
    	scanf("%d %lld", &y, &ind);
    	ind++;
    	currmax=(long long)pow(2, y);
     
    	while(currmax>1){
    		if(ind<=(currmax/2)){
    			if(y%2==1){
    				comp++;
    			}
    			ind=(currmax/2)-ind+1;
    		}
    		else{
    			ind=ind-(currmax/2);
    		}
    		currmax=currmax/2;
    		y--;
    	}
     
    	if(comp%2==0){
    		printf("red\n");
    	}
    	else{
    		printf("blue\n");
    	}
     
    	return 0;
    } 
