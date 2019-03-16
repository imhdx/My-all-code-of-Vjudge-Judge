#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int mod=1e9+7;
const double PI=3.141592653598793;
typedef long long ll;
ll poww(ll a,ll b){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod;b>>=1;}return res;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
int a[100010];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            x=x%m;
            a[i]=x;
        }
        sort(a,a+n);
        int maxx=0;
        int st=0;
        int la=n-1;
        int j,k;
        while (st<=la)
        {
            if ((a[st]+a[la])%m==m-1)
            {
                maxx=max(maxx,m-1);
                break;
            }
            else if (a[st]+a[la]<m-1)
            {
                maxx=max(maxx,(a[st]+a[la])%m);
                j=st+1;
                while (j<=la&&a[st]==a[j])
                {
                    j++;
                }
                st=j;
            }
            else
            {
                maxx=max(maxx,(a[st]+a[la])%m);
                j=la-1;
                while (j>=st&&a[la]==a[j])
                {
                    j--;
                }
                la=j;
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
