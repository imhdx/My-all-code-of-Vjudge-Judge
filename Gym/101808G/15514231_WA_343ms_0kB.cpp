#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long int n,x,y;
        int flag=0;
        scanf("%lld%lld%lld",&n,&x,&y);
        if (y%x!=0||(n==1&&x!=y)) flag=1;
        int i,j;
        int cnt=0;
        for (i=0;i<n;i++)
        {
            long long int xxx;
            scanf("%lld",&xxx);
            if (xxx%x!=0||y%xxx!=0) cnt++;
        }
        if (flag==1) printf("-1\n");
        else
            printf("%d\n",cnt);
    }
    return 0;
}
