#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct note
{
    int a,b,c;
}que[2000];
int dp[2000];
bool cmp(struct note aa,struct note bb)
{
    if (aa.a==bb.a)
    {
        return aa.b>bb.b;
    }
    return aa.a>bb.a;
}
int main()
{
    int cnt=0;
    int i,j;
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        cnt++;
        memset(dp,0,sizeof(dp));
        int maxx=0;
        j=0;
        for (i=0;i<n;i++)
        {
            int q,w,e;
            scanf("%d%d%d",&q,&w,&e);
            que[j].a=q;
            que[j].b=w;
            que[j].c=e;
            j++;
            que[j].a=w;
            que[j].b=q;
            que[j].c=e;
            j++;
            que[j].a=w;
            que[j].b=e;
            que[j].c=q;
            j++;
            que[j].a=e;
            que[j].b=w;
            que[j].c=q;
            j++;
            que[j].a=q;
            que[j].b=e;
            que[j].c=w;
            j++;
            que[j].a=e;
            que[j].b=q;
            que[j].c=w;
            j++;
        }
        int k=j;
        sort(que,que+k,cmp);
        maxx=0;
        for (i=0;i<k;i++)
        {
            dp[i]=que[i].c;
            int qqq=0;
            for (j=0;j<i;j++)
            {
                if (que[i].a<que[j].a&&que[i].b<que[j].b)
                {
                    if (qqq<dp[j]) qqq=dp[j];
                }
            }
            dp[i]=qqq+que[i].c;
            if (maxx<dp[i]) maxx=dp[i];
        }
        printf("Case %d: maximum height = ",cnt);
        printf("%d\n",maxx);

    }
    return 0;
}
