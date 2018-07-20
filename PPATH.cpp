    #include <stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int num;
    	int ans;
    }node;
    int vis[10000];
    int isprime(int n){
    	for(int i=2;i*i<=n;i++){
    		if(n%i==0){
    			return 0;
    		}
    	}
    	return 1;
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
    		for(int i=0;i<10000;i++){
    			vis[i]=0;
    		}
    		int u, v, flag=1, o, t, h, th, newnum;
    		scanf("%d %d", &u, &v);
    		node temp, pui;
    		temp.num=u;
    		temp.ans=0;
    		queue<node> q;
    		q.push(temp);
    		while(!q.empty()){
    			temp=q.front();
    			q.pop();
    			if(temp.num==v){
    				flag=0;
    				printf("%d\n", temp.ans);
    				break;
    			}
    			vis[temp.num]=1;
    			pui.ans=temp.ans+1;
    			o=temp.num%10;
    			t=temp.num%100-o;
    			h=temp.num%1000-t-o;
    			th=temp.num%100000-h-t-o;
    			// printf("%d %d %d %d %d\n", temp.num, th, h, t, o);
    			for(int i=0;i<=9;i++){
    				newnum=temp.num-o+i;
    				if(vis[newnum]!=1 && isprime(newnum)==1){
    					pui.num=newnum;
    					q.push(pui);
    				}
    			}
    			for(int i=0;i<=9;i++){
    				newnum=temp.num-t+10*i;
    				if(vis[newnum]!=1 && isprime(newnum)==1){
    					pui.num=newnum;
    					q.push(pui);
    				}
    			}
    			for(int i=0;i<=9;i++){
    				newnum=temp.num-h+100*i;
    				if(vis[newnum]!=1 && isprime(newnum)==1){
    					pui.num=newnum;
    					q.push(pui);
    				}
    			}
    			for(int i=1;i<=9;i++){
    				newnum=temp.num-th+1000*i;
    				if(vis[newnum]!=1 && isprime(newnum)==1){
    					pui.num=newnum;
    					q.push(pui);
    				}
    			}
     
    		}
    		if(flag==1){
    			printf("Impossible\n");
    		}
    	}
    	return 0;
    } 
