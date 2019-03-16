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
long long int k[50010];
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    long long int mo=1;
    long long int sum=0;
    long long int maxx=1;
    int i=1;
    int m=n;
    while (n--)
    {
        k[i]=mo;
        if (mo<=0||mo>50000)
        {
            break;
        }
        i++;
        sum=sum+mo;
        if (b!=0)
        {
            mo=sum+1;
            maxx=max(maxx,mo);
            b--;
        }
        else if (a!=0)
        {
            mo=maxx+1;
            maxx=max(maxx,mo);
            a--;
        }
    }
    if (n!=-1)
    {
        printf("-1\n");
    }
    else
    {
        for (int i=1;i<=m;i++)
            printf("%lld ",k[i]);
        printf("\n");
    }
    return 0;
}
