#include<cstdio>
#include<algorithm>
using namespace std;
struct note
{
    int a,b;
}que[5010];
int book[5010];
int cnt[5010];
bool cmp(struct note qq,struct note pp)
{
    if (qq.a!=pp.a)
    return qq.a<pp.a;
    return qq.b<pp.b;
}
int main()
{
    int n,m;
    int x1,y1,x2,y2;
    int i,j;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        for (i=0;i<5010;i++)
            book[i]=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&que[i].a,&que[i].b);
        }
        sort(que,que+n,cmp);
        int qq,pp;
        for (i=0;i<m;i++)
        {
            scanf("%d%d",&qq,&pp);
            for (j=0;j<n;j++)
            {
                if ((qq-que[j].a)*(pp-y2)-(pp-y1)*(qq-que[j].b)<0) {book[j]++;break;}
            }
            if (j==n) book[j]++;
        }
        for (i=0;i<=m;i++)
            cnt[i]=0;
        for (i=0;i<=n;i++)
        {
            cnt[book[i]]++;
        }
        printf("Box\n");
        for(i=1;i<=n;i++)
        {
            if (cnt[i]!=0)
            printf("%d: %d\n",i,cnt[i]);
        }
    }
    return 0;
}
