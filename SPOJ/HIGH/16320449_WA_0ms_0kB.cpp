#include<bits/stdc++.h>
using namespace std;
double a[15][15];
bool zero(long long x)
{
    if (x==0) return 0;
    return 1;
}
/*
long long det(int n)
{
    long long mul,Result=1;
    long long b[n];
    for(int i=1; i<=n; i++)
        b[i]=i;
    for(int i=2; i<=n; i++)
    {
        if(zero(a[b[i]][i]))
            for(int j=i+1; j<=n; j++) //但是整行数据一个一个互换比较浪费，所以我在这里用b[i]数据当下表，然后更换一下b[i],b[j]所代表的值就达到的更换的效果
                if(!zero(a[b[j]][i]))
                {
                    swap(b[i],b[j]);
                    Result*=-1;
                    break;
                }
        Result*=a[b[i]][i];
        for(int j=i+1; j<=n; j++)
            if(!zero(a[b[j]][i]))
            {
                mul=a[b[j]][i]/a[b[i]][i];
                for(int k=i; k<n; k++)
                    a[b[j]][k]-=a[b[i]][k]*mul;
            }
    }
    Result=abs(Result);
    return Result;

}
*/
///求的是n-1阶余子式
double det(int n)
{
    for (int i=2;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (a[j][i])
            {
                double num=-a[j][i]/a[i][i];
                for (int k=i;k<=n;k++)
                    a[j][k]+=num*a[i][k];
            }
        }
    }
    double ans=1.0;
    for (int i=2;i<=n;i++)
        ans*=a[i][i];
    return ans;
}
/*
long long det(int n)///高斯消元
{
    long long res=1;
    for (int i=2;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            while (a[j][i])
            {
                long long t=a[i][i]/a[j][i];
                for (int k=i;k<=n;k++)
                    a[i][k]-=a[j][k]*t;
                for (int k=i;k<=n;k++)
                    swap(a[i][k],a[j][k]);
                res=-res;
            }
        }
        if (!a[i][i])
            return 0;
        res=res*a[i][i];
    }
    return abs(res);
}
*/
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        int n,m;
        scanf("%d%d",&n,&m);
        int x,y;
        for (int i=0; i<m; i++)
        {
            scanf("%d%d",&x,&y);
            ///度数矩阵-邻接矩阵
            a[x][x]++;///x点和y点的度数均加一
            a[y][y]++;
            a[x][y]--;///图G的度数矩阵，满足当i!=j时,d[i][j]=0;当i==j时,d[i][i]等于vi的度数。
            a[y][x]--;
        }
        printf("%lld\n",(long long)fabs(det(n)));
    }
    return 0;
}
