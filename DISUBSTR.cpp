    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	struct Node* arr[128];
    	vector<int> v;
    }node;
    node* root=NULL;
    char a[1005];
    int n;
    void insert(node* pt, int ind){
    	if(ind==n){
    		return;
    	}
     
    	if(pt->arr[(int)a[ind]]!=NULL){
    		insert(pt->arr[(int)a[ind]], ind+1);
    	}
    	else{
    		pt->arr[(int)a[ind]]=(node*)malloc(sizeof(node));
    		insert(pt->arr[(int)a[ind]], ind+1);
    		pt->v.push_back((int)a[ind]);
    	}
    }
    long long fn(node* pt){
    	long long partial=0;
    	for(int i=0;i<(pt->v.size());i++){
    		partial+=(1+fn(pt->arr[(pt->v[i])]));
    	}
    	return partial;
    } 
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		root=(node*)malloc(sizeof(node));
    		scanf("%s", a);
    		n=strlen(a);
     
    		for(int i=n-1;i>=0;i--){
    			insert(root, i);
    		}
    		
    		printf("%lld\n", fn(root));
    		// fnfree(root);
    	}
    	return 0;
    } 
