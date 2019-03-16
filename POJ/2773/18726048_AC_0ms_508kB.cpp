#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
vector<int> pri;
int f(int x)
{
    int len=pri.size();
    int ans=0;
    for (int i=1;i<(1ll<<len);i++)
    {
        int tmp=0;
        int p=1;
        for (int j=0;j<len;j++)
        {
            if ((i>>j)&1)
            {
                tmp++;
                p*=pri[j];
            }
        }
        if (tmp&1) ans+=x/p;
        else ans-=x/p;
    }
    return x-ans;
}
signed main()
{
    int n,k;
    while (scanf("%lld%lld",&n,&k)!=EOF)
    {
        pri.clear();
        for (int i=2;1ll*i*i<=n;i++)
        {
            if (n%i==0)
            {
                pri.push_back(i);
                while (n%i==0) n/=i;
            }
        }
        if (n!=1) pri.push_back(n);

        int l=1ll;
        int r=(1ll<<60);
        int ans=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (f(mid)>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        printf("%lld\n",ans);

    }
    return 0;
}
