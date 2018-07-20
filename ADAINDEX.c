    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    char aux[1000006];
    typedef struct Node{
    	struct Node* arr[26];
    	int count;
    }node;
    void insert(int l, int ind, node* p){
    	if(ind>=l){
    		return;
    	}
     
    	if(p->arr[aux[ind]-'a']==NULL){
    		p->arr[aux[ind]-'a']=(node*)malloc(sizeof(node));
    		p->arr[aux[ind]-'a']->count=1;
    	}
    	else{
    		p->arr[aux[ind]-'a']->count++;
    	}
    	return insert(l, ind+1, p->arr[aux[ind]-'a']);
    }
    int fn(int l, int ind, node* p){
    	if(p->arr[aux[ind]-'a']==NULL){
    		return 0;
    	}
    	
    	if(ind==l-1){
    		return p->arr[aux[ind]-'a']->count;
    	}
    	else{	
    		return fn(l, ind+1, p->arr[aux[ind]-'a']);
    	}
    }
    int main(){
    	node* root=(node*)malloc(sizeof(node));
    	int n, q;
    	scanf("%d %d", &n, &q);
    	while(n--){
    		scanf("%s", aux);
    		// printf("%s\n", aux);
    		insert(strlen(aux), 0, root);
    	}
    	while(q--){
    		scanf("%s", aux);
    		printf("%d\n", fn(strlen(aux), 0, root));
    	}
    	return 0;
    } 
