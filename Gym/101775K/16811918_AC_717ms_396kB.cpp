#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=0x3f3f3f3f;
const ll INFll=2*INF*INF;
const double PI=4*atan(1.0);
ll poww(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int d[100005];
int main()
{
    int k=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        for (int i=1;i<=a;i++)
            scanf("%d",&d[i]);
        while (n--)
        {
            int deng=a;
            int jing=1;
            while (deng>d[jing])
            {
                deng-=d[jing];
                jing++;
            }
            a=jing;
            b=deng;
        }
        printf("Case #%d: %d-%d\n",k++,a,b);
    }


    return 0;
}
