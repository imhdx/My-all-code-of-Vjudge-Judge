#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
bool check[10000010];
int prim[1000010];
int cnt=0;
void init()
{
    cnt=0;
    int i;
    for (i=2;i<10000010;i++)
    {
        if (check[i]==0)
        {
            prim[cnt++]=i;
            for (long long j=1ll*i*i;j<10000010;j=j+i)
                check[j]=1;
        }
    }
}
int main()
{
    int t=1;
    int T;
    init();
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for (int i=0;i<cnt;i++)
        {
            if (prim[i]+prim[i]<=n)
            {
                if (check[n-prim[i]]==0)
                    ans++;
            }
            else
                break;
        }
        printf("Case %d: ",t++);
        printf("%d\n",ans);
    }
    return 0;
}
