    #include<stdio.h>
    #include<stdlib.h>
    typedef struct Node{
    	struct Node* arr[10];
    	int end;
    }node;
    int flag;
    void insert(char a[], node* p){
    	if(a[0]=='\0'){
    		return;
    	}
     
    	if(p->arr[a[0]-'0']==NULL){
    		p->arr[a[0]-'0']=(node*)malloc(sizeof(node));
    		if(a[1]=='\0'){
    			p->arr[a[0]-'0']->end=1;
    			return;
    		}
    		else{
    			p->arr[a[0]-'0']->end=0;
    			return insert(&a[1], p->arr[a[0]-'0']);
    		}
    	}
    	else{
    		if(p->arr[a[0]-'0']->end==1){
    			flag=1;
    			return;
    		}
    		else{
    			if(a[1]=='\0'){
    				flag=1;
    				return;
    			}
    			return insert(&a[1], p->arr[a[0]-'0']);
    		}
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		node* root=(node*)malloc(sizeof(node));
    		int n;
    		flag=0;
    		scanf("%d", &n);
    		char temp[15];
    		for(int i=0;i<n;i++){
    			scanf("%s", temp);
    			insert(temp, root);
    		}
     
    		if(flag){
    			printf("NO\n");
    		}
    		else{
    			printf("YES\n");
    		}
    	}
    	return 0;
    } 
