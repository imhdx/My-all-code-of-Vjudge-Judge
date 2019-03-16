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
    int mo;
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if (b==0&&n==a+1&&n!=1)
        printf("-1\n");
    else
    {
        if (b==0)
        {
            printf("1 ");
            n=n-1;
            mo=1;
            while (n--)
            {
                printf("%d ",mo);
                if (a!=0)
                {
                    a--;
                    mo=mo+1;
                }
            }
        }
        else
        {
            mo=1;
            while (n--)
            {
                printf("%d ",mo);
                if (a!=0)
                {
                    a--;
                    mo=mo+1;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
