    #include<stdio.h>
    #include<bits/stdc++.h>
    using namespace std;
    long long int arr[30005];
    vector<long long int> seg[120009];
    void merge(int a, int b, int ind){
        int i=0, j=0;
        while(i<seg[a].size() && j<seg[b].size()){
        	if(seg[a][i]<seg[b][j]){
             seg[ind].push_back(seg[a][i]);
             i++;
         }		
         else{
             seg[ind].push_back(seg[b][j]);
             j++;
         }
     }
     while(i<seg[a].size()){
      seg[ind].push_back(seg[a][i]);
      i++;
    }
    while(j<seg[b].size()){
      seg[ind].push_back(seg[b][j]);
      j++;	
    }
    }
    int fnc(int l, int r, int par, int child){
    	if(child==0){
           if(seg[2*par].size()!=0){
              return 2*par;
          }
          else{
              if(r==l){
                 seg[2*par].push_back(arr[r]);
                 return 2*par;
             }
             merge(fnc(l, (r+l)/2, 2*par, 0), fnc((r+l)/2+1, r, 2*par, 1), 2*par);
             return 2*par;
         }
     }
     else{
       if(seg[2*par+1].size()!=0){
          return 2*par+1;
      }
      else{
          if(r==l){
             seg[2*par+1].push_back(arr[r]);
             return 2*par+1;
         }
         merge(fnc(l, (r+l)/2, 2*par+1, 0), fnc((r+l)/2+1, r, 2*par+1, 1), 2*par+1);
         return 2*par+1;
     }
    }
    }
    int bs(int a, long long x){
    	int l=0, r=seg[a].size(), mid;
    	r--;
    	while(r>=l){
    		mid=(l+r)/2;
    		if(r==l){
    			return l;
    		}
    		
           if((r-l)==1){
              if(seg[a][l]>x){
                 return l;
             }
             else{
                 return r;
             }
         }
         
         if(seg[a][mid]>x){
          r=mid;
      }
      else{
          l=mid+1;
      }
    }
    }
    int Search(int l, int r, int s, int e, int ind, long long x){
       if(l<=s&&r>=e){
          if(x<seg[ind][0]){
             return seg[ind].size();
         }
         if(x>=seg[ind][seg[ind].size()-1]){
             return 0;
         }
         return seg[ind].size()-bs(ind, x);
     }
     if(l>(s+e)/2){
      return Search(l, r, (s+e)/2+1, e, 2*ind+1, x);
    }
    if(r<=(s+e)/2){
      return Search(l, r, s, (s+e)/2, 2*ind, x);
    }
    else{
      return Search(l, (s+e)/2, s, (s+e)/2, 2*ind, x) + Search((s+e)/2+1, r, (s+e)/2+1, e, 2*ind+1, x);
    }
    }
    int main(){
       int n;
       scanf("%d", &n);
       for(int i=0;i<n;i++){
          scanf("%lld", &arr[i]);
      }
      merge(fnc(0, (n-1)/2, 1, 0), fnc((n+1)/2, n-1, 1, 1), 1);
      int q, l, r, prev=0;
      long long k;
      scanf("%d", &q);
      while(q--){
          scanf("%d %d %lld", &l, &r, &k);
          l=l^prev;
          r=r^prev;
          k=k^prev;
          if(l<1){
            l=1;
          }
          if(r>n){
            r=n;
          }
          if(l>r){
            printf("0\n");
            prev=0;
            continue;
          }
          prev=Search(l-1, r-1, 0, n-1, 1, k);
          printf("%d\n", prev);
      }
      return 0;
    }  
