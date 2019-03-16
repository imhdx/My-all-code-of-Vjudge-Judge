#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int inf=1e9+7;
int a[150020];
int cc=0;
bool f(int x)
{
    if (x==1) return 1;
    cc++;
    if (cc>10) return 0;
    int ans=0;
    while (x)
    {
        ans+=(x%10)*(x%10);
        x/=10;
    }
    return f(ans);
}
int main()
{
    int cnt=0;
    for (int i=1;cnt<150020;i++)
    {
        cc=0;
        if (f(i)) a[cnt++]=i;
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d\n",&n);
        n--;
        printf("%d\n",a[n]);
    }
    return 0;
}