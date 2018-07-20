    #include <stdio.h>
    #include <iostream>
    #include <stdlib.h>
    #include <queue>
    #include <set>
    #include <iterator>
    #define pii pair<int,int>
     
    using namespace std;
     
    int main ()
    {
    // 	ios_base :: sync_with_stdio(0);
    // 	cin.tie(0); cout.tie(0);
    	int n, d;
    	scanf("%d %d",&n,&d);
    	int h[100001];
    	for (int i=1; i<=n; i++) 
    		scanf("%d",&h[i]);
    	queue <pii> Q;
    	for (int i=1; i<=n; i++) 
    		Q.push(make_pair(i,i));
    	set <pii> S;
    	for (int i=1; i<n; i++)
    		if (abs(h[i] - h[i+1]) <= d) 
    		{
    			Q.push(make_pair(i,i+1));
    			S.insert(make_pair(i,i+1));
    		}
    		int x, y;
    		while (!Q.empty())
    		{
    			x = Q.front().first;
    			y = Q.front().second;
    			Q.pop();
    			if ((x - 1 > 0 && y + 1 <= n) && (x - 1 != y + 1))
    			{
    				if (abs(h[x-1]-h[y+1]) <= d )
    				{
    					if (S.find(make_pair(x-1,y+1)) == S.end())
    					{
    						Q.push(make_pair(x-1,y+1));
    						S.insert(make_pair(x-1,y+1));
    					}
    				}
    			}
    			if ((x - 1 > 0) && (x - 1 != y - 1))
    			{
    				if (abs(h[x-1]-h[y-1]) <= d )
    				{
    					if (S.find(make_pair(x-1,y-1)) == S.end())
    					{
    						Q.push(make_pair(x-1,y-1));
    						S.insert(make_pair(x-1,y-1));
    					}
    				}
    			}
    			if ((y + 1 <= n) && (x + 1 != y + 1))
    			{
    				if (abs(h[x+1]-h[y+1]) <= d )
    				{
    					if (S.find(make_pair(x+1,y+1)) == S.end())
    					{
    						Q.push(make_pair(x+1,y+1));
    						S.insert(make_pair(x+1,y+1));
    					}
    				}
    			}
    			if ((x + 1 <= n) && (y - 1 > 0) && (x + 1 != y - 1) && (x + 1 < y - 1))
    			{
    				if (abs(h[x+1]-h[y-1]) <= d)
    				{
    					if (S.find(make_pair(x+1,y-1)) == S.end())
    					{
    						Q.push(make_pair(x+1,y-1));
    						S.insert(make_pair(x+1,y-1));
    					}	
    				}
    			} 
    		}
    		set <pii> :: iterator it;
    		for (it=S.begin(); it != S.end(); it++)
    			printf("%d %d\n",it->first,it->second);
    		return 0;
    	} 
