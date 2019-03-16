#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int shi[201];
int main() //完整的鱼 不完整的鱼
{
    int a[200];
    int m,n,x;
    while (scanf("%d%d%d",&m,&n,&x)!=EOF)
    {
        memset(shi,0,201*sizeof(int));
        int i,j;
        int q=0,w=0;
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for (i=1;i<=x;i++)
        {
            for (j=0;j<n;j++)
            {
                if (shi[j]==0)
                {
                    if (q+1<=m)
                    {
                        q++;
                        shi[j]++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (shi[j]==a[j])
                {
                    w++;
                    shi[j]=0;
                }
                else
                    shi[j]++;
            }
        }
        printf("%d %d\n",m-q,q-w);
    }
    return 0;
}
