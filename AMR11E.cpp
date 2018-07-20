#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
vector<int> primes;
vector<int> answers;
void generate(){
	primes.push_back(2);
	int isprime;
	for(int i=3;i<10000;i++){
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
	answers.push_back(30);
	int t=1;
	int T;
	scanf("%d", &T);
	while(T--){
		int n, count;
		scanf("%d", &n);
 
		if(t>=n){
			printf("%d\n", answers[n-1]);
		}
		else{
			// printf("pui\n");
			for(int i=answers[answers.size()-1]+1;t<n;i++){
				count=0;
				for(int j=0;primes[j]<=i;j++){
					if(i%primes[j]==0){
						count++;
						if(count==3){
							answers.push_back(i);
							t++;
							break;
						}
					}
				}
			}
			printf("%d\n", answers[n-1]);
		}
	}
	return 0;
}
