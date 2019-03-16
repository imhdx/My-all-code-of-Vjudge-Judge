#include<stdio.h>
#include<string,h>
int a[6000];
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
    int ttt;
    scanf("%d",&ttt);
    while (ttt--)
    {
        scanf("%d",&n);
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
        printf("%d\n",s);
    }
    return 0;
}