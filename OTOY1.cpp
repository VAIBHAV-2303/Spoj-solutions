        #include<stdio.h>
        #include<bits/stdc++.h>
        const int m=1e9+7;
        using namespace std;
        vector<int> primes;
        int cprod[505];
        int dp[505][505]; 
        int fn(int p, int power){
        	if(p<0){
        		if(power==0){
        			return 1;
        		}
        		else{
        			return 0;
        		}
        	}
        	if(dp[p][power]==-1){
        		if(power==0){
        			dp[p][power]=1;
        		}
        		else{
        			int partial=0;
        			int curr=1;
        			for(int i=0;i<=power;i++){
        				partial=(partial+((1LL*curr*fn(p-1, power-i))%m))%m;
        				curr=(1LL*curr*primes[p])%m;
        			}
        			dp[p][power]=partial;
        		}
        	}
        	return dp[p][power];
        }
        void generate(){
            primes.push_back(2);
            int isprime;
            for(int i=3;primes.size()<=501;i+=2){
           		isprime=1;
            	for(int j=0;primes[j]*primes[j]<=i;j++){
            		if(i%primes[j]==0){
            			isprime=0;
            			break;
           			}
            	}
            	if(isprime){
            		primes.push_back(i);
           		}
            }
        }
        int main(){
           	generate();
           	cprod[0]=1;
           	for(int i=1;i<501;++i){
           		cprod[i]=(1LL*cprod[i-1]*(primes[i]-1))%m;
           	}  
            for(int i=0;i<501;++i){
            	for(int j=0;j<501;j++){
           			dp[i][j]=-1;
           		}
            }
         
            int T, k, p, ans;
           	scanf("%d", &T);
            for(int t=1;t<=T;++t){
            	scanf("%d %d", &k, &p);
            	ans=(1LL*cprod[p-1]*fn(p-1, k-p))%m;
            	printf("Case %d: %d\n", t, ans);
           	}
            return 0;
        }   
