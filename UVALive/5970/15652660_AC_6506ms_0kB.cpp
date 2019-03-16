#include<bits/stdc++.h>
using namespace std;
map<int,int> M;
struct Query
{
    int L,R,id;
}node[100005];
int unit;
bool cmp(Query a,Query b)
{
    if (a.L/unit!=b.L/unit) return a.L/unit<b.L/unit;
    return a.R<b.R;
}
int a[100005];
int vis[100005];
double ans[100005];
int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        M.clear();
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        unit=(int)sqrt(n);
        int cnt=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (M.count(a[i])==0)
                M[a[i]]=cnt++;
        }
        int m;
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            node[i].L=x;
            node[i].R=y;
            node[i].id=i;
        }
        sort(node,node+m,cmp);
        int l=node[0].L;
        int r=node[0].R;
        long long sum=0;
        cnt=0;
        for (int i=l;i<=r;i++)
        {
            if (vis[M[a[i]]]==0)
            {
                sum+=a[i];
                cnt++;
            }
            vis[M[a[i]]]++;
        }
        ans[node[0].id]=(1.0*sum)/cnt;
        for (int i=1;i<m;i++)
        {
            while (l<node[i].L)
            {
                vis[M[a[l]]]--;
                if (vis[M[a[l]]]==0)
                {
                    cnt--;
                    sum-=a[l];
                }
                l++;
            }
            while (l>node[i].L)
            {
                l--;
                vis[M[a[l]]]++;
                if (vis[M[a[l]]]==1)
                {
                    cnt++;
                    sum+=a[l];
                }
            }
            while (r<node[i].R)
            {
                r++;
                vis[M[a[r]]]++;
                if (vis[M[a[r]]]==1)
                {
                    cnt++;
                    sum+=a[r];
                }
            }
            while (r>node[i].R)
            {
                vis[M[a[r]]]--;
                if (vis[M[a[r]]]==0)
                {
                    cnt--;
                    sum-=a[r];
                }
                r--;
            }
            ans[node[i].id]=(1.0*sum)/cnt;
        }
        printf("Case %d:\n",t++);
        for (int i=0;i<m;i++)
            printf("%.6f\n",ans[i]);
    }
    return 0;
}
