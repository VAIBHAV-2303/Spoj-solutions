#include<stdio.h>
int main()
{
    int T, u;
    scanf("%d", &T);
    for(u=0;u<T;u++)
    {
        int n, i, k, j;
        scanf("%d", &n);
        int a[200];
        for(i=0;i<200;i++)
        {
            a[i]=0;
        }
        a[0]=1;
        for(i=1;i<=n;i++)
        {
            for(k=0;k<200;k++)
            {
                if(a[k]!=0)
                {
                    a[k]=a[k]*i;
                }
            }
            for(j=1;j<200;j++)
            {
                if((a[j-1]/10)!=0)
                {
                    a[j]=((a[j-1])/10)+a[j];
                    a[j-1]=a[j-1]%10;
                }
            }
        }
 
        for(i=199;i>=0;i--)
        {
            if(a[i]!=0)
            {
                for(j=i;j>=0;j--)
                {
                    printf("%d", a[j]);
                }
                break;
            }
        }
        printf("\n");
    }
	return 0;
}
