#include<cstdio>
#include<cstdlib>

using namespace std;

int n,m;
int pre[30010];

int get(int hh)
{
    if (pre[hh]==hh) return hh;
    return pre[hh]=get(pre[hh]);
}
void jie(int aa,int dd)
{
    int xx=get(aa);
    int yy=get(dd);
    if (xx!=yy) pre[xx]=yy;
}
int main()
{

    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) break;
        int i,j;
        for (i=0;i<n;i++)
        {
            pre[i]=i;
        }
        for (i=0;i<m;i++)
        {
            int k,kk;
            scanf("%d",&k);
            scanf("%d",&kk);
            for(j=1;j<k;j++)
            {
                int q;
                scanf("%d",&q);
                jie(q,kk);
            }
        }
        int ans=0;
        for (i=0;i<n;i++)
        {
            if (get(i)==get(0))
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
