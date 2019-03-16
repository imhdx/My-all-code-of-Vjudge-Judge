#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f;
const ll INFll=2*INF*INF;
const double PI=4*atan(1.0);
ll poww(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main()
{
    int kk=1;
    int a[1000];
    int b[12];
    int cnt=0;
    a[cnt]=48;
    cnt++;
    for (int i=8;i>=1;i>>=1)
    {
        a[cnt++]=i;
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<5;i++) scanf("%d",&b[i]);
        long long int s=0;
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            int j;
            for (j=0;j<cnt;j++)
            {
                if (x>a[j])  x-=a[j];
                else
                    break;
            }
            s+=b[j];
        }
        printf("Case #%d: ",kk++);
        printf("%lld\n",s*10000);
    }
    return 0;
}
