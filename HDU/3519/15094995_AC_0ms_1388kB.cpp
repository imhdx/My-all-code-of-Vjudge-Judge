#include<bits/stdc++.h>
using namespace std;
const int mod=10007;
long long int poww(long long int a,long long int b)
{
    long long res=1;
    while (b>0)
    {
        if (b&1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
int ju[4];
int res[4];
void jupoww(int ju[],int b)
{
    res[0]=1;
    res[1]=0;
    res[2]=1;
    res[3]=0;
    while (b>0)
    {
        if (b&1)
        {
            int tmp[4];
            tmp[0]=((res[0]*ju[0])%mod+(res[1]*ju[2])%mod)%mod;
            tmp[1]=((res[0]*ju[1])%mod+(res[1]*ju[3])%mod)%mod;
            tmp[2]=((res[2]*ju[0])%mod+(res[3]*ju[2])%mod)%mod;
            tmp[3]=((res[2]*ju[1])%mod+(res[3]*ju[3])%mod)%mod;
            for (int i=0; i<4; i++)
                res[i]=tmp[i];
        }
        int tmp[4];
        tmp[0]=((ju[0]*ju[0])%mod+(ju[1]*ju[2])%mod)%mod;
        tmp[1]=((ju[0]*ju[1])%mod+(ju[1]*ju[3])%mod)%mod;
        tmp[2]=((ju[2]*ju[0])%mod+(ju[3]*ju[2])%mod)%mod;
        tmp[3]=((ju[2]*ju[1])%mod+(ju[3]*ju[3])%mod)%mod;
        for (int i=0; i<4; i++)
            ju[i]=tmp[i];
        b=b>>1;
    }
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==1||n==2)
        {
            printf("0\n");
            continue;
        }
        int i;

        ju[0]=1;
        ju[1]=1;
        ju[2]=1;
        ju[3]=0;
        if (n-1>=1)
            jupoww(ju,n-1);
        long long a=((res[0]*2)%mod+(res[1]*2)%mod)%mod;
        long long int ans=((poww(2,n)-a)%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
