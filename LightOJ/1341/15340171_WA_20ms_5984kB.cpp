#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
bool check[1000005];
int prim[1000005];
int cnt=0;
void init()
{
    int i;
    for (i=2;i*i<=1000006;i++)
    {
        if (!check[i])
        {
            prim[cnt++]=i;
            for (long long j=1ll*i*i;j<1000000;j=j+i)
                check[j]=true;
        }
    }
}
int main()
{
    //freopen("debug\\in.txt","r",stdin),freopen("debug\\out.txt","w",stdout);
    init();
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        printf("Case %d: ",t++);
        if (b*b>=a)
        {
            printf("%d\n",0);
            continue;
        }
        long long int ans=1;
        long long int c=a;
        for (int i=0;i<cnt&&prim[i]<=sqrt(c);i++)
        {
            int cc=1;
            while (c%prim[i]==0)
            {
                cc++;
                c/=prim[i];
            }
            ans*=cc;
        }
        if (c>1)
            ans*=2;
        ans=ans/2;
        for (int i=1;i<b;i++)
        {
            if (a%i==0)
                ans--;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
