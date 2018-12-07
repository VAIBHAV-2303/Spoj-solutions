    #include<bits/stdc++.h>
    using namespace std;
    long long int a[200005];
    typedef struct Node{
    	struct Node* left;
    	struct Node* right;
    }node;
    void insert(long long int x, node* p, long long int cur){
    	if(cur==0){
    		return;
    	}
     
    	if((x&cur)==cur){
    		if(p->right==NULL){
    			p->right=(node*)malloc(sizeof(node));
    		}
    		insert(x, p->right, cur>>1);
    	}
    	else{
    		if(p->left==NULL){
    			p->left=(node*)malloc(sizeof(node));
    		}
    		insert(x, p->left, cur>>1);
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
     
    		node* root=(node*)malloc(sizeof(node));
    		node* p;
    		int n;
    		long long x, temp, totmax, cur, curans;
    		scanf("%d %lld", &n, &x);
    		for(int i=0;i<n;i++){
    			scanf("%lld", &a[i]);
    		}
     
    		totmax=a[0]^x;
    		// printf("%lld\n", totmax);
    		insert(a[0], root, 4294967296);
     
    		for(int i=1;i<n;i++){
    			a[i]=a[i]^a[i-1];
    			temp=x^a[i];
    			// printf("%lld\n", temp);
    			cur=4294967296;
    			p=root;
    			curans=0;
    			while(cur!=0){
    				if((temp&cur)==cur){
    					if(p->left!=NULL){
    						curans+=cur;
    						p=p->left;
    					}
    					else{
    						p=p->right;
    					}
    				}
    				else{
    					if(p->right!=NULL){
    						curans+=cur;
    						p=p->right;
    					}
    					else{
    						p=p->left;
    					}
    				}
    				cur>>=1;
    			}
     
    			totmax=max(max(curans, temp), totmax);
    			insert(a[i], root, 4294967296);
    		}
     
    		printf("%lld\n", totmax^x);
    		free(root);
    	}
    	return 0;
    } 