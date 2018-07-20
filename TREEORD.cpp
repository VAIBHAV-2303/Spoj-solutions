    #include<stdio.h>
    using namespace std;
    int pre[9000], pos[9000], in[9000], flag=0, n;
    void check(int l, int prer, int posl, int r, int s, int e){
        if(r<0 || r>=n || l>=n || l<0 || prer<l || posl>r){
            return;
        }
        if(pre[l]!=pos[r]){
            // printf("%d %d %d %d %d %d\n", l, prer, posl, r, s, e);
            flag=1;
            return;
        }
        int count=0, lcount, rcount;
        for(int i=s;i<=e;i++){
            count++;
            if(in[i]==pre[l]){
                lcount=count-1;
                rcount=(e-s+1)-count;
                check(l+1, l+lcount, posl, posl+lcount-1, s, i-1);
                check(l+lcount+1, prer, posl-lcount, r-1, i+1, e);
                return;
            }
        }
    }
    int main(){
        scanf("%d", &n);
     
        for(int i=0;i<n;i++){
            scanf("%d", &pre[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d", &pos[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d", &in[i]);
        }
     
        check(0, n-1, 0, n-1, 0, n-1);
     
        if(flag){
            printf("no\n");
        }
        else{
            printf("yes\n");
        }
     
        return 0;
    } 
