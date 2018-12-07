    #include<bits/stdc++.h>
    using namespace std;
    long long ans=0;
    typedef struct Pui{
    	int root;
    	int height;
    }pui;
    pui arr[100005];
    typedef struct Node{
    	int u;
    	int v;
    	long long weight;
    	bool operator<(const struct Node &pui)
    	{
    		return weight < pui.weight;
    	}
    }node;
    vector<node> a;
    pui find(int ver){
    	if(arr[ver].root==ver){
    		return arr[ver];
    	}
    	else{
    		arr[ver]=find(arr[ver].root);
    		return arr[ver];
    	}
    }
    int main(){
    	int T;
    	scanf("%d", &T);
    	while(T--){
     
    		a.clear();
     
    		int n, m, count=0;
    		long long x;
    		pui ru, rv;
    		node temp;
    		scanf("%d %d", &n, &m);
    		for(int i=1;i<=n;i++){
    			arr[i].height=1;
    			arr[i].root=i;
    		}
    		while(m--){
    			scanf("%d %d %lld", &temp.u, &temp.v, &temp.weight);
    			x=2;
    			count=0;
    			while(x<=temp.weight){
    				count++;
    				x<<=1;
    			}
    			temp.weight=count;
    			a.push_back(temp);
    		}
     
    		sort(a.begin(), a.end());
    		ans=0;
     
    		for(int i=0;i<a.size();i++){
    			ru=find(a[i].u);
    			rv=find(a[i].v);
    			if(ru.root==rv.root){
    				continue;
    			}
    			else{
    				if(ru.height>rv.height){
    					arr[rv.root].root=ru.root;
    				}
    				else if(ru.height<rv.height){
    					arr[ru.root].root=rv.root;
    				}
    				else{
    					arr[rv.root].root=ru.root;
    					arr[rv.root].height++;
    				}
    				ans+=a[i].weight;
    			}
    		}
    		printf("%lld\n", ans+1);
    	}
    	return 0;
    } 