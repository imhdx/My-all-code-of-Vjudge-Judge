#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<math.h>
using namespace std;
const int MAXN=5e5+7;
int belong[MAXN],num,block,l[MAXN],r[MAXN];
int a[MAXN];
int n;
vector<int>v[MAXN];
void build()
{
    block=sqrt(n*log2(n));
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
int ask(int tl,int tr,int x)
{
    if (tl>tr) return 0;
    int i;
    int ans=0;
    if (belong[tl]==belong[tr])
    {
        for (i=tl; i<=tr; i++)
        {
            if (a[i]>x) ++ans;
        }
        return ans;
    }
    for (i=tl; i<=r[belong[tl]]; i++)
        if (a[i]>x) ++ans;
    for (i=belong[tl]+1; i<belong[tr]; i++)
    {
        int index=lower_bound(v[i].begin(),v[i].end(),x)-v[i].begin();
        if (index>0)
            ans+=block-index;
    }
    for (i=l[belong[tr]]; i<=tr; i++)
        if (a[i]>x) ++ans;
    return ans;
}
int main()
{
    int i;
    while (scanf("%d",&n)!=EOF&&n)
    {
        build();
        for (i=1;i<=num;i++)
            v[i].clear();
        for (int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            v[belong[i]].push_back(a[i]);
        }
        for (i=1; i<=num; i++)
            sort(v[i].begin(),v[i].end());
        int ANS=0;
        for (i=1;i<=n;i++)
        {
            ANS+=ask(1,i-1,a[i]);
        }
        printf("%d\n",ANS);
    }
    return 0;
}
