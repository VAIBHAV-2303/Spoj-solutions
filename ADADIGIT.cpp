    #include<stdio.h>
    #include<math.h>
    #include<bits/stdc++.h>
    using namespace std;
    vector<int> primes;
    vector<int> v;
    vector<int> a;
    long long maxnumdiv=-1, maxsum=-1, maxnumdivans=10000000000, maxsumans=10000000000;
    int spfa[100000];
    long long current;
    int spf(int x){
    	if(x<100000){
    		return spfa[x];
    	}
    	for(int i=0;primes[i]*primes[i]<=x;i++){
    		if((x%primes[i])==0){
    			return primes[i];
    		}
    	}
    	return x;
    }
    void generate(){
    	int isprime;
    	primes.push_back(2);
    	spfa[2]=2;
    	for(int i=3;i<100000;i++){
    		isprime=1;
    		for(int j=0;primes[j]*primes[j]<=i;j++){
    			if(i%primes[j]==0){
    				isprime=0;
    				spfa[i]=primes[j];
    				break;
    			}
    		}
    		if(isprime==1){
    			spfa[i]=i;
    			primes.push_back(i);
    		}
    	}
    }
    int num(int n){
    	int pui, temp, x, ong;
    	if(n==1){
    		current=1;
    		return 1;
    	}
    	int isprime=1;
    	for(int j=0;primes[j]*primes[j]<=n;j++){
    		if(n%primes[j]==0){
    			isprime=0;
    			break;
    		}
    	}
    	if(isprime==0){
    		a.clear();
    		while(n!=1){
    			a.push_back(spf(n));
    			n=n/spf(n);
    		}
    		pui=1;
    		current=1;
    		int i=0;
    		while(i<a.size()){
    			temp=1;
    			x=a[i];
    			ong=a[i];
    			while((i+1)<a.size() && a[i+1]==a[i]){
    				temp++;
    				ong*=a[i];
    				x+=ong;
    				i++;
    			}
    			pui*=(temp+1);
    			current*=(x+1);
    			i++;
    		}
    		return pui;
    	}
    	else{
    		current=n+1;
    		return 2;
    	}
    }
    void permute(int ind){
    	long long x=0;
    	int temp;
    	if(ind==v.size()-1){
    		for(int i=0;i<v.size();i++){
    			x+=(v[i]*pow(10, i));	
    		}
    		
    		if(num(x)>maxnumdiv){
    			maxnumdiv=num(x);
    			maxnumdivans=x;
    		}
    		else if(num(x)==maxnumdiv){
    			if(x<maxnumdivans){
    				maxnumdivans=x;
    			}
    		}
     
    		if(current>maxsum){
    			maxsum=current;
    			maxsumans=x;
    		}
    		else if(current==maxsum){
    			if(x<maxsumans){
    				maxsumans=x;
    			}
    		}
    		return;
    	}
     
    	for(int i=ind;i<v.size();i++){
    		temp=v[ind];
    		v[ind]=v[i];
    		v[i]=temp;
    		permute(ind+1);
    		temp=v[ind];
    		v[ind]=v[i];
    		v[i]=temp;
    	}
    }
    int main(){
     
    	generate();
     
    	int n, temp;
    	scanf("%d", &n);
    	for(int i=0;i<n;i++){
    		scanf("%d", &temp);
    		v.push_back(temp);
    	}
    	permute(0);
    	printf("%lld %lld\n", maxnumdivans, maxsumans);
    	return 0;
    } 
