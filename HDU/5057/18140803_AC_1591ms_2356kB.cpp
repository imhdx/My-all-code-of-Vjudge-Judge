#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
int belong[MAXN],num,block,l[320],r[320];
int a[MAXN];
int n,m;
int v[320][12][12];
long long mi[12];
void build()
{
    block=sqrt(n);
    num=n/block;
    if (n%block)
        num++;
    int i;
    for (i=1; i<=num; i++)
        l[i]=(i-1)*block+1,r[i]=i*block;
    r[num]=n;
    for (i=1; i<=n; i++)
        belong[i]=(i-1)/block+1;
}
int ask(int tl,int tr,int x,int y)
{
    int i;
    int ans=0;
    if (belong[tl]==belong[tr])
    {
        for (i=tl; i<=tr; i++)
            ans+=((a[i]/mi[x])%10==y);
        return ans;
    }
    for (i=tl; i<=r[belong[tl]]; i++)
        ans+=((a[i]/mi[x])%10==y);
    for (i=belong[tl]+1; i<belong[tr]; i++)
        ans+=v[i][x][y];
    for (i=l[belong[tr]]; i<=tr; i++)
        ans+=((a[i]/mi[x])%10==y);
    return ans;
}
int main()
{
    mi[1]=1;
    for (int i=2; i<=10; i++)
        mi[i]=10ll*mi[i-1];
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        build();
        memset(v,0,sizeof(v));
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            int tmp=a[i];
            for (int j=1; j<=10; j++)
            {
                int tt=tmp%10;
                tmp/=10;
                v[belong[i]][j][tt]++;
            }
        }
        char op[6];
        for (int i=0; i<m; i++)
        {
            scanf("%s",op);
            if (op[0]=='Q')
            {
                int ll,rr,dd,xx;
                scanf("%d%d%d%d",&ll,&rr,&dd,&xx);
                printf("%d\n",ask(ll,rr,dd,xx));
            }
            else
            {
                int dd,xx;
                scanf("%d%d",&dd,&xx);
                int tmp1=a[dd];
                for (int j=1; j<=10; j++)
                {
                    int tt=tmp1%10;
                    tmp1/=10;
                    v[belong[dd]][j][tt]--;
                }
                a[dd]=xx;
                tmp1=xx;
                for (int j=1; j<=10; j++)
                {
                    int tt=tmp1%10;
                    tmp1/=10;
                    v[belong[dd]][j][tt]++;
                }
                a[dd]=xx;
            }
        }
    }
    return 0;
}
