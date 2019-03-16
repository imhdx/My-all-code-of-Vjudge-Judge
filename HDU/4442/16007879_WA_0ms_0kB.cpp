#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b;
}que[100005];
const int mod=365*24*60*60;
bool cmp(struct node q,struct node p)
{
    if (q.a==p.a) return q.b<p.b;
    return q.a<p.a;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        for (int i=0;i<n;i++)
        {
            scanf("%d%d",&que[i].a,&que[i].b);
        }
        sort(que,que+n,cmp);
        long long int sum=0;
        for (int i=0;i<n;i++)
        {
            sum=(sum+que[i].a+sum*que[i].b%mod)%mod;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
