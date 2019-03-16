#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long a[1000010];
int main()
{
    a[1]=1;
    a[2]=1;
    for (int i=3;i<1000010;i++)
        a[i]=((i-1)*a[i-1]%mod+(i-2)*a[i-2]%mod)%mod;
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",t++,a[n]);
    }
    return 0;
}
