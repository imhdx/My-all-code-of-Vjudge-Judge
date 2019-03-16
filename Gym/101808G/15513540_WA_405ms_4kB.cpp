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
        int n,x,y;
        int flag=0;
        scanf("%d%d%d",&n,&x,&y);
        if (y%x!=0) flag=1;
        int i,j;
        int cnt=0;
        for (i=0;i<n;i++)
        {
            int xxx;
            scanf("%d",&xxx);
            if (gcd(xxx,x)!=x||lcm(xxx,y)!=y) cnt++;
        }
        if (flag==1) printf("-1\n");
        else
            printf("%d\n",cnt);
    }
    return 0;
}
