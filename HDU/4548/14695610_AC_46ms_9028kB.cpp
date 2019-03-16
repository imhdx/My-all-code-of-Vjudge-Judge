#include<cstdio>
#include<cmath>
using namespace std;
int a[1000005];
int prim[1000005];
int main()
{
    int T;
    int i,j;
    prim[2]=0;
    prim[1]=1;
    prim[3]=0;
    for (i=1;i<1000005;i++)
    {
        if (prim[i]==0)
        {
            for (j=2;i*j<1000005;j++)
                prim[i*j]=1;
        }
    }
    a[0]=0;
    for (i=1;i<=1000000;i++)
    {
        if (prim[i]==0)
        {
            int tmp=i;
            int sum=0;
            while (tmp!=0)
            {
                sum=sum+tmp%10;
                tmp=tmp/10;
            }
            if (prim[sum]==0) a[i]=a[i-1]+1;
            else
                a[i]=a[i-1];
        }
        else
        {
            a[i]=a[i-1];
        }
    }
    scanf("%d",&T);
    int cnt=1;
    while (T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("Case #%d: ",cnt++);
        printf("%d\n",a[y]-a[x-1]);
    }
    return 0;
}
