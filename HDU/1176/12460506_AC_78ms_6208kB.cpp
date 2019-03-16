#include<stdio.h>
int MAX,maxx=-1,j,x,t,i,n,a[100008][12];
int max(int a,int b)
{
    if (a<b) return b;
    return a;
}
int main()
{
    while (scanf("%d",&n)!=EOF&&n!=0)
    {
        MAX=-1;
        maxx=-1;
        for (i=0;i<100008;i++)
            for (j=0;j<12;j++)
            a[i][j]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&x,&t);
            if (maxx<t) maxx=t;
            a[t][x]=a[t][x]+1;
        }
        for (t=maxx-1;t>=0;t--)
        {
            for (x=0;x<=10;x++)
            {
                if (x==0)
                    a[t][x]=max(a[t+1][x],a[t+1][x+1])+a[t][x];
                else if (x==10)
                    a[t][x]=max(a[t+1][x],a[t+1][x-1])+a[t][x];
                else
                    a[t][x]=max(max(a[t+1][x],a[t+1][x-1]),a[t+1][x+1])+a[t][x];
            }
        }
        printf("%d\n",a[0][5]);
    }
    return 0;
}
