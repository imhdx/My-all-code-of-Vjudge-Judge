#include<stdio.h>
int a[5010],b[5010];
int book[5010];
int main()
{
    int n,m;
    int x1,y1,x2,y2;
    int i,j;
    while (scanf("%d%d%d%d%d%d",&n,&m,&x1,&y1,&x2,&y2)!=EOF)
    {
        for (i=0;i<5010;i++)
            book[i]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        int qq,pp;
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&qq,&pp);
            for (j=0;j<n;j++)
            {
                if ((qq-a[j])*(pp-y2)-(pp-y1)*(qq-b[j])<0) {book[j]++;break;}
            }
            if (j==n) book[j]++;
        }
        for (i=0;i<=n;i++)
        {
            printf("%d: %d\n",i,book[i]);
        }
        printf("\n");
    }
    return 0;
}
