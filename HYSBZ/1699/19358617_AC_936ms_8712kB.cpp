#include<bits/stdc++.h>
using namespace std;
int n,q;
const int maxn=50004;
int lo[maxn];
void init()
{
    lo[1]=0;
    for (int i=2;i<maxn;i++) lo[i]=lo[i/2]+1;
}
int a[maxn];
int stma[maxn][18];
int stmi[maxn][18];
void rmq()
{
    for (int i=1;i<=n;i++) stma[i][0]=stmi[i][0]=a[i];
    for (int j=1;j<18;j++)
    {
        for (int i=1;i+(1<<j)-1<=n;i++)
        {
            stma[i][j]=max(stma[i][j-1],stma[i+(1<<(j-1))][j-1]);
            stmi[i][j]=min(stmi[i][j-1],stmi[i+(1<<(j-1))][j-1]);
        }
    }
}
int askma(int l,int r)
{
    int len=lo[r-l+1];
    return max(stma[l][len],stma[r-(1<<len)+1][len]);
}
int askmi(int l,int r)
{
    int len=lo[r-l+1];
    return min(stmi[l][len],stmi[r-(1<<len)+1][len]);
}
int main()
{
    init();
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    rmq();
    while (q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",askma(l,r)-askmi(l,r));
    }
    return 0;
}
