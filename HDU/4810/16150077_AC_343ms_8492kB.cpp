#include<bits/stdc++.h>
using namespace std;
long long int a[1020];
int num[66];
long long c[1005][1005];
const int mod=1e6+3;
void init()
{
    for (int i=0;i<1005;i++)
    {
        c[i][0]=1;
        for (int j=0;j<i;j++)
        {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
        c[i][i]=1;
    }
}
int main()
{
    init();
    /*
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<=i;j++)
        {
            printf("%lld%c",c[i][j]," \n"[j==i]);
        }
    }
    printf("\n");
    */
    int n,k;
    while (scanf("%d",&n)!=EOF)
    {
        memset(num,0,sizeof(num));
        for (int i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            for (int j=0;j<64;j++)
            {
                if ((a[i]>>j)&1)
                {
                    num[j]++;
                }
            }
        }
        /*
        for (int j=0;j<64;j++)
        {
            printf("%d ",num[j]);
        }
        printf("\n");
        */
        ///因为最后是求和所以每一种情况都有考虑  所以对于每一位来说 总之都要算的且每一位不对应起来也可以！！！
        ///num[j]为每一位1出现的个数
        ///按位来算每一位的贡献  每一位的贡献在于1   而1来自从每一位的1中挑选出奇数个1
        for (int i=1;i<=n;i++)
        {
            long long ans=0;
            for (int k=0;k<64;k++)///统计每一位
            {
                for (int j=1;j<=num[k]&&j<=i;j+=2)///挑选出奇数个1
                {
                    ans=(ans+c[n-num[k]][i-j]*c[num[k]][j]%mod*((1ll<<k)%mod)%mod)%mod;
                }
            }
            printf("%lld%c",ans," \n"[i==n]);
        }
    }

    return 0;
}
