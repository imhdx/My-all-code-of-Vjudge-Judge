#include<cstdio>

using namespace std;

int n,m;
int pre[1001];
int get(int k)
{
    if (pre[k]==k) return k;
    return pre[k]=get(pre[k]);
}

void lian(int q,int p)
{
    int x=get(q);
    int y=get(p);
    if (x!=y)
    {
        pre[x]=y;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        int i,j;
        for (i=1;i<=n;i++)
        {
            pre[i]=i;
        }
        for (i=1;i<=m;i++)
        {
            int q,p;
            scanf("%d%d",&q,&p);
            lian(q,p);
        }
        int ans=0;
        for (i=1;i<=n;i++)
        {
            if (i==get(i))
                ans++;
        }
        printf("%d\n",ans);

    }

    return 0;
}
