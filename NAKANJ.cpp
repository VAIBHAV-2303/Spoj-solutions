    #include <stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    typedef struct Node{
    	int num;
    	int ans;
    }node;
    int vis[100];
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
     
    		for(int i=0;i<100;i++){
    			vis[i]=0;
    		}
    		int v, o, t, newnum;
    		char c1, c2, c3, c4;
     
    		scanf("\n%c%c %c%c", &c1, &c2, &c3, &c4);
    		
    		node temp, pui;
    		temp.num=(10*(int)(c1-'a'+1))+(int)(c2-'1'+1);
    		v=(10*(int)(c3-'a'+1))+(int)(c4-'1'+1);
    		// printf("%d\n", v);
    		temp.ans=0;
    		queue<node> q;
    		q.push(temp);
    		while(!q.empty()){
    			temp=q.front();
    			q.pop();
    			if(temp.num==v){
    				printf("%d\n", temp.ans);
    				break;
    			}
    			vis[temp.num]=1;
    			pui.ans=temp.ans+1;
     
    			//upar
    			newnum=temp.num+20-1;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    			newnum=temp.num+20+1;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    			//left
    			newnum=temp.num+10-2;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    			newnum=temp.num-10-2;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    			//right
    			newnum=temp.num+10+2;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    			newnum=temp.num-10+2;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    			//niche
    			newnum=temp.num-20+1;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    			newnum=temp.num-20-1;
    			if(vis[newnum]!=1 && newnum<=88 && newnum>=11 && newnum%10>=1 && newnum%10 <=8){
    				pui.num=newnum;
    				q.push(pui);
    			}
    		}
    	}
    	return 0;
    } 
