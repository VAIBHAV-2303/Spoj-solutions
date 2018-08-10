        #include<stdio.h>
        #include<bits/stdc++.h>
        using namespace std;
        int dp[100][100];
        map<string,bool> processed[100][100];
        string s1, s2;
        set<string> S;
        string curr;
        set<string>::iterator it;
        int LCS(int i, int j){
            if(dp[i][j]==-1){
                if(i>=s1.size() || j>=s2.size()){
                    dp[i][j]=0;
                }
                else if(s1[i]==s2[j]){
                    dp[i][j]=1+LCS(i+1, j+1);
                }
                else{
                    dp[i][j]=max(LCS(i+1, j), LCS(i, j+1));
                }
            }
            return dp[i][j];
         
        }
        void fn(int i, int j, int pui){
            if(processed[i][j].find(curr)!=processed[i][j].end()){
                return;
            }
            processed[i][j][curr]=true;
            if(curr.size()==pui){
                S.insert(curr);
                return;
            }
            if(s1[i]==s2[j]){
                curr.push_back(s1[i]);
                fn(i+1, j+1, pui);
                curr.pop_back();
            }
            else{
                if(dp[i+1][j]>dp[i][j+1]){
                    fn(i+1, j, pui);
                }
                else if(dp[i+1][j]<dp[i][j+1]){
                    fn(i, j+1, pui);
                }
                else{
                    fn(i, j+1, pui);
                    fn(i+1, j, pui);
                }
            }
        }
        int main(){
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            
            int T;
            cin >> T;
            while(T--){
                for(int i=0;i<100;i++){
                    for(int j=0;j<100;j++){
                        dp[i][j]=-1;
                        processed[i][j].clear();
                    }
                }
     
                s1.clear();
                s2.clear();
                S.clear(); 
                cin >> s1;
                cin >> s2;
         
                int pui=LCS(0, 0);
         
                curr.clear();
                fn(0, 0, pui);
            
                it = S.begin();
                while(it!=S.end()){
                    printf("%s\n", (*it).c_str());
                    it++;
                }
            }
            return 0;
        }  
