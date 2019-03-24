#include<bits/stdc++.h>
using namespace std;
const int maxn=10004;
const int maxm=100005;
int pre[maxn];
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
int xx[maxm];
int yy[maxm];
vector<int> v;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
    for (int i=0;i<=n;i++) pre[i]=i;
    for (int i=0;i<m;i++)
    {
        scanf("%d%d",&xx[i],&yy[i]);
    }
    int ans=n;
    v.clear();
    for (int i=m-1;i>=0;i--)
    {
        v.push_back(ans);
        int x=getx(xx[i]);
        int y=getx(yy[i]);
        if (x!=y)
        {
            ans--;
            pre[x]=y;
        }

    }
    for (int i=v.size()-1;i>=0;i--)
        printf("%d\n",v[i]);
    }
    return 0;
}
