#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b;
}que[100005];
bool cmp(struct node q,struct node p)
{
    return 1ll*q.a*p.b<1ll*p.a*q.b;
}
const long long mod=1ll*365*24*60*60;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0 ) return 0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&que[i].a,&que[i].b);
        }
        sort(que,que+n,cmp);
        long long ans=0;
        long long tmp=0;
        for (int i=0;i<n;i++)
        {
            ans=(ans+ans*que[i].b%mod+que[i].a)%mod;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
