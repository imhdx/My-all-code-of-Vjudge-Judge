#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int n;
bool check(int x)
{
    int sum=0;
    for (int i=1;i<=n;i++) sum+=x-a[i];
    return sum>=x;
}
signed main()
{
    scanf("%I64d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);

    int l=*max_element(a+1,a+1+n);
    int r=2e18;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+r>>1;
        if (check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    printf("%I64d\n",ans);
    return 0;
}
