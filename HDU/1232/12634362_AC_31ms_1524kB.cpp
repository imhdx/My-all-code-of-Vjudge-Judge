#include<stdio.h>
int a[2000];
int getf(int q)
{
    if (a[q]==q) return q;
    a[q]=getf(a[q]);
    return a[q];
}
void jie(int q,int w)
{
    if (getf(q)!=getf(w))
    {
        a[getf(w)]=getf(q);
    }
}
int main()
{
    int n,m;
    int i,j,k;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        scanf("%d",&m);
        for (i=0;i<=n;i++)
            a[i]=i;
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&j,&k);
            jie(j,k);
        }
        int s=0;
        for (i=1;i<=n;i++)
        {
            if (a[i]==i)
                s++;
        }
        printf("%d\n",s-1);
    }
    return 0;
}
