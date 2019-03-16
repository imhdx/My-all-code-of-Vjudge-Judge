#include<stdio.h>
int a[9999],b[9999],c[9999];
int m;
void build(int qq,int ww,int oo,int pp)
{
    if (qq>ww) return ;
    if (oo>pp) return ;
    if (qq==ww) {c[m++]=a[qq];return ;}
    if (oo==pp) {c[m++]=a[oo];return ;}
    int k=0;
    for (k=0;k+oo<=pp;k++)
    {
        if (b[k+oo]==a[qq]) break;
    }
    build(qq+1,qq+k,oo,oo+k-1);
    build(qq+k+1,ww,k+oo+1,pp);
    c[m++]=b[k+oo];
    return ;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=0;i<n;i++) scanf("%d",&a[i]);
        for (i=0;i<n;i++) scanf("%d",&b[i]);
        m=0;
        build(0,n-1,0,n-1);
        printf("%d",c[0]);
        for (i=1;i<m;i++)
        printf(" %d",c[i]);
        printf("\n");
    }
    return 0;
}
