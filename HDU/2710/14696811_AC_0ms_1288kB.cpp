#include<cstdio>
#include<cmath>
using namespace std;
int prim[20005];
int main()
{
    int i;
    int cnt=1;
    for (i=2;i<20005;i++)
    {
        if (prim[i]==0)
        {
            for (long long j=1;i*j<20005;j++)
            {
                prim[i*j]=i;
            }
        }
    }

    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int maxx=1;
        int x;
        for (i=0;i<n;i++)
        {
            scanf("%d",&x);
            if (prim[x]>prim[maxx]) maxx=x;
        }
        printf("%d\n",maxx);
    }

    return 0;
}
