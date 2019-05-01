#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
int nxt[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++)
        {
            nxt[i]=-1;
            for (int j=i+1;j<=n;j++)
            {
                if (a[j]<a[i])
                {
                    nxt[i]=j;
                    break;
                }
            }
        }
        int m;
        scanf("%d",&m);
        while (m--)
        {
            int l,r;scanf("%d%d",&l,&r);
            int ans=a[l];
            l=nxt[l];
            while (l!=-1&&l<=r)
            {
                ans%=a[l];
                l=nxt[l];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
