#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
bool check[1000100];
int prim[1000100];
void init()
{
    int i;
    int cnt=0;
    for (i=2;i<1000100;i++)
    {
        if (check[i]==0)
        {
            prim[cnt++]=i;
            for (long long j=1ll*i*i;j<1000100;j=j+i)
                check[j]=true;
        }
    }
}
int main()
{
    init();
    printf("hi\n");

    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case %d: ",t++);
        if (b>=sqrt(a))
        {
            printf("%d\n",0);
            continue;
        }
        long long int ans=1;
        int c=a;
        for (int i=0;prim[i]<=sqrt(c);i++)
        {
            int cc=1;
            while (c%prim[i]==0)
            {
                cc++;
                c/=prim[i];
            }
            ans*=cc;
        }
        if (c!=1)
            ans*=2;
        ans=ans/2;
        for (int i=1;i<b;i++)
        {
            if (a%b==0)
                ans--;
        }
        printf("%d\n",ans);
    }

    return 0;
}
