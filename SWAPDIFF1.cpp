    #include<stdio.h>
    long long a[200005], L[200005], R[200005], ans;
    void merge(int l, int mid, int r){
       for(int i=0;i<(mid-l+1);i++){
          L[i]=a[l+i];
      }
      for(int i=0;i<(r-mid);i++){
          R[i]=a[mid+1+i];
      }
      int i=0, j=0, k=l;
      while((i<(mid-l+1))&&(j<(r-mid))){
          if(L[i]<=R[j]){
             a[k]=L[i];
             k++;
             i++;
         }
         else{
             ans+=mid-l+1-i;
             a[k]=R[j];
             k++;
             j++;
         }	
     }
     while(j<(r-mid)){
      a[k]=R[j];
      j++;
      k++;
    }
    while(i<(mid-l+1)){
      a[k]=L[i];
      i++;
      k++;
    }
    }
    void split(int l, int r){
       if(r>l){
          int mid=(l+(r-l)/2);
          split(l, mid);
          split(mid+1, r);
          merge(l, mid, r);
      }
    }
    int main(){
       int T;
       scanf("%d", &T);
       while(T--){
          int n;
          scanf("%d", &n);
          for(int i=0;i<n;i++){
             scanf("%lld", &a[i]);
         }
         ans=0;
         split(0, n-1);
         printf("%lld\n", ans);
     }
     return 0;
    }  
