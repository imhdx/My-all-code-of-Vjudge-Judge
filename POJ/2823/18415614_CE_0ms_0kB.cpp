#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e6+7;
int st[maxn][20];
int st2[maxn][20];
int a[maxn];
int n;
void init()
{
    for (int i=1;i<=n;i++) st[i][0]=st2[i][0]=a[i];
    for (int i=1;(1<<i)<=n;i++)
    {
        for (int j=1;j+(1<<i)-1<=n;j++)
        {
            st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
            st2[j][i]=min(st2[j][i-1],st2[j+(1<<(i-1))][i-1]);
        }
    }

}
int len;
int ask1(int l,int r)
{
    return max(st[l][len],st[r-(1<<len)+1][len]);
}
int ask2(int l,int r)
{
    return min(st2[l][len],st2[r-(1<<len)+1][len]);
}
int main()
{
    int k;
    scanf("%d%d",&n,&k);
    len=(int)(log(k)/log(2));
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    init();

    for (int i=1;i+k-1<=n;i++)
    {
        printf("%d%c",ask2(i,i+k-1)," \n"[i+k-1==n]);
    }
    for (int i=1;i+k-1<=n;i++)
    {
        printf("%d%c",ask1(i,i+k-1)," \n"[i+k-1==n]);
    }

    return 0;
}
