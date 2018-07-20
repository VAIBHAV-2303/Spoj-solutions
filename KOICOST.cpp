    #include<stdio.h>
    #include<queue>
    using namespace std;
    long long M=1000000000; 
    typedef struct Node{
    	long long par;
    	long long count;
    	long long height;
    }node;
    #define pli pair<long long int, pair<long long int, long long int> >
    priority_queue < pli > pq;
    node dp[100005];
    long long find(long long ver){
    	if(dp[ver].par==-1){
    		return ver;
    	}
    	return find(dp[ver].par);
    }
    long long nC2(long long x){
    	return (((x*(x-1))/2)%M);
    }
    int main(){
    	long long ans=0, running=0;
    	for(long long i=0;i<100005;i++){
    		dp[i].par=-1;
    		dp[i].height=0;
    		dp[i].count=1;
    	}
    	long long n, m, u, v, w, ru, rv, hu, hv, total;
    	scanf("%lld %lld", &n, &m);
    	
    	while(m--){
    		scanf("%lld %lld %lld", &u, &v, &w);
    		pq.push(make_pair(w, make_pair(u, v)));
    	}
    	pli pui;
    	while(!pq.empty()){
    		pui = pq.top();
    		pq.pop();
    		u=pui.second.first;
    		v=pui.second.second;
    		w=pui.first;
    		ru=find(u);
    		rv=find(v);
    		if(ru==rv){
    			ans= ( (ans%M) +  ( (running)  * (w%M))%M )%M;
    		}	
    		else{
    			hu=dp[ru].height;
    			hv=dp[rv].height;
    			running = running - nC2(dp[ru].count);
    			running = running - nC2(dp[rv].count);
    			total = dp[ru].count + dp[rv].count;
    			running = ((running%M) + nC2(total))%M;
    			ans = ((ans%M) + ( (running) * (w%M))%M )%M;
    			if(hu>hv){
    				dp[rv].par=ru;
    				dp[ru].count+=dp[rv].count;
    			}
    			else if(hv>hu){
    				dp[ru].par=rv;
    				dp[rv].count+=dp[ru].count;
    			}
    			else{
    				dp[ru].par=rv;
    				dp[rv].count+=dp[ru].count;
    				dp[rv].height++;
    			}
    		}
    	}
     
    	printf("%lld\n", ans);
     
    	return 0;
    } 
