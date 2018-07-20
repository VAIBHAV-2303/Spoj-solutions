    #include<stdio.h>
    typedef struct Node{
    	int data;
    	int ind;
    }node;
    node a[100005], L[100005], R[100005];
    void merge(int l, int mid, int r){
    	for(int i=0;i<(mid-l+1);i++){
    		L[i]=a[l+i];
    	}
    	for(int i=0;i<(r-mid);i++){
    		R[i]=a[mid+1+i];
    	}
    	int i=0, j=0, k=l;
    	while((i<(mid-l+1))&&(j<(r-mid))){
    		if(L[i].data<R[j].data){
    			a[k]=L[i];
    			k++;
    			i++;
    		}
    		else if(L[i].data>=R[j].data){
    			a[k]=R[j];
    			k++;
    			j++;
    		}	
    	}
    	while(j<(r-mid)){
    		a[k]=R[j];
    		j++;
    		k++;
    	}
    	while(i<(mid-l+1)){
    		a[k]=L[i];
    		i++;
    		k++;
    	}
    }
    void split(int l, int r){
    	if(r>l){
    		int mid=(l+(r-l)/2);
    		split(l, mid);
    		split(mid+1, r);
    		merge(l, mid, r);
    	}
    }
    int main(){
    	int n;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &a[i].data);
    		a[i].ind=i+1;
    	}
    	split(0, (n-1));
    	for(int i=0;i<n;i++){
    		printf("%d ", a[i].ind);
    	}
    	printf("\n");
    	return  0;
    }
     
