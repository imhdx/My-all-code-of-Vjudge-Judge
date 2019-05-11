
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int n,block,num;
int l[400],r[400],belong[maxn];
vector<int> v[400];
void build()
{
    block=sqrt(n);
    num=n/block;if (n%block) num++;
    for (int i=1;i<=n;i++)
    {
        belong[i]=(i-1)/block+1;
    }
    for (int i=1;i<=num;i++)
    {
        l[i]=block*(i-1)+1;
        r[i]=block*i;
    }
    r[num]=min(r[num],n);
}
int ask(int ll,int rr,int x)
{
    if (belong[ll]==belong[rr])
    {
        int cnt=0;
        for (int i=ll;i<=rr;i++)
        {
            if (a[i]<=x) cnt++;
        }
        return cnt;
    }
    int cnt=0;
    for (int i=ll;i<=r[belong[ll]];i++) if (a[i]<=x) cnt++;
    for (int i=belong[ll]+1;i<belong[rr];i++) cnt+=distance(v[i].begin(),upper_bound(v[i].begin(),v[i].end(),x));
    for (int i=l[belong[rr]];i<=rr;i++) if (a[i]<=x) cnt++;
    return cnt;
}
int main()
{
    int T;
    int tt=1;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        build();
        for (int i=1;i<=num;i++) v[i].clear();
        for (int i=1;i<=n;i++) v[belong[i]].push_back(a[i]);

        for (int i=1;i<=num;i++) sort(v[i].begin(),v[i].end());
        printf("Case %d:\n",tt++);
        while (m--){
            int ll,rr,x;scanf("%d%d%d",&ll,&rr,&x);
            printf("%d\n",ask(ll+1,rr+1,x));
        }

    }
    return 0;
}