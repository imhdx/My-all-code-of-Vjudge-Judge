#include<cstdio>
#include<cmath>
using namespace std;
int prim[1000015];
int mark[1000015];
int main()
{
    int i;
    int cnt=1;
    for (i=0;i<1000015;i++)
    {
        prim[i]=mark[i]=0;
    }
    for (i=2;i<1000015;i++)
    {
        if (prim[i]==0)
        {
            mark[i]=cnt++;
            for (long long j=1;i*j<1000015;j++)
            {
                prim[i*j]=i;
            }
        }
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        printf("%d\n",mark[prim[n]]);
    }
    return 0;
}
