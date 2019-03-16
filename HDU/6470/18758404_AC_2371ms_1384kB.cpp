#include<bits/stdc++.h>
using namespace std;
const int mod=123456789;
void mul(long long a[8][8],long long b[8][8])
{
    long long res[8][8];
    for (int i=0;i<8;i++) for (int j=0;j<8;j++) res[i][j]=0;
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++)
        {
            for (int k=0;k<8;k++)
                (res[i][j]+=a[i][k]*b[k][j]%mod)%=mod;
        }
    }
    for (int i=0;i<8;i++) for (int j=0;j<8;j++) a[i][j]=res[i][j];
}
void poww(long long a[8][8],long long b)
{
    long long res[8][8];
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++) res[i][j]=0;
        res[i][i]=1;
    }

    while (b)
    {
        if (b&1) mul(res,a);
        mul(a,a);
        b>>=1;
    }
    for (int i=0;i<8;i++) for (int j=0;j<8;j++) a[i][j]=res[i][j];
}
int main()
{
    long long res[8][8];
    for (int i=0;i<8;i++)
    {
        for (int j=0;j<8;j++) res[i][j]=0;
        res[i][i]=1;
    }
    mul(res,res);

    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long n;
        scanf("%lld",&n);
        if (n==1)
        {
            printf("1\n");
            continue;
        }
        else if (n==2)
        {
            printf("1\n");
            continue;
        }
        long long ans[8][8]=
        {
            1,2,1,3,3,1,0,0,
            1,0,0,0,0,0,0,0,
            0,0,1,0,0,0,0,0,
            0,0,1,1,0,0,0,0,
            0,0,1,2,1,0,0,0,
            0,0,1,3,3,1,0,0,
            0,0,0,0,0,0,1,0,
            0,0,0,0,0,0,0,1,
        };

        poww(ans,n-2);

        long long res[8][8];
        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
                res[i][j]=0;
        }
        res[0][0]=1;
        res[1][0]=2;
        res[2][0]=1;
        res[3][0]=2;
        res[4][0]=4;
        res[5][0]=8;
        res[6][0]=0;
        res[7][0]=0;
        long long tmp[8][8];
        for (int i=0;i<8;i++) for (int j=0;j<8;j++) tmp[i][j]=0;

        for (int i=0;i<8;i++)
        {
            for (int j=0;j<8;j++)
            {
                for (int k=0;k<8;k++)
                {
                    (tmp[i][j]+=ans[i][k]*res[k][j]%mod)%=mod;
                }
            }
        }


        if (n&1) tmp[0][0]--;
        else tmp[0][0]++;
        printf("%lld\n",tmp[0][0]);
    }

    return 0;
}