#include<math.h>
#include<stdio.h>
int n;
int r,k;
int f(int k)
{
    if ((int)(log10(n*(k-1)+k)/log10(k))==(log10(n*(k-1)+k)/log10(k)))
        return k*((log10(n*(k-1)+k)/log10(k))-1);
    else if ((int)(log10((n-1)*(k-1)+k)/log10(k))==(log10((n-1)*(k-1)+k)/log10(k)))
        return k*((log10((n-1)*(k-1)+k)/log10(k))-1);
    return -1;
}
int main()
{
    int min,t,i,l,r,mid,midmid,tt;
    while (scanf("%d",&n)!=EOF)
    {
        l=2;
        r=n;
        min=999999;
        t=0;
        for (i=2;i<=n;i++)
        {
            tt=f(i);
            if (tt==-1)
                continue;
            if (min>tt) {min=tt;t=i;}
        }
        printf("%d %d\n",f(t)/t,t);
    }
    return 0;
}
