#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct note
{
    int w,s;
    int num;
}que[2000];
bool cmp(struct note aa,struct note bb)
{
    return aa.s>bb.s;
}
int dp[2000];
int lu[2000];
void f(int kk)
{
    int i;
    if (lu[kk]==kk)
    {
        printf("%d\n",que[kk].num);
        return ;
    }
    f(lu[kk]);
    printf("%d\n",que[kk].num);
    return ;
}
int main()
{
    int i=0;
    while (scanf("%d%d",&que[i].w,&que[i].s)!=EOF)
    {
        que[i].num=i+1;
        i++;
    }
    int n=i;
    sort(que,que+i,cmp);
    int j;
    memset(dp,0,sizeof(dp));
    int maxi=0;
    for (i=0;i<n;i++)
    {
        int qqq=0;
        int ll=-1;
        for (j=0;j<i;j++)
        {
            if (que[j].w<que[i].w&&que[j].s>que[i].s)
            {
                if (qqq<dp[j]) {qqq=dp[j];ll=j;}
            }
        }
        if (ll==-1) lu[i]=i;
        else
            lu[i]=ll;
        dp[i]=qqq+1;
        if (dp[maxi]<dp[i]) maxi=i;
    }
    printf("%d\n",dp[maxi]);
    f(lu[maxi]);
    printf("%d\n",que[maxi].num);
    return 0;
}
