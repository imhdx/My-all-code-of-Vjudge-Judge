#include<bits/stdc++.h>
using namespace std;
int a[1000011];
#define MAXN 10000010
#define MAXL 20000010
int prim[MAXN];
int check[MAXL];
long long int num[10000010];
int main()
{
    int i;
    int cnt=0;

    int tot = 0;
    for (int i = 2; i < MAXL; ++i)
    {
        if (!check[i])
        {
            prim[tot++] = i;
        }
        for (int j = 0; j < tot; ++j)
        {
            if (i * prim[j] > MAXL)
            {
                break;
            }
            check[i*prim[j]] = 1;
            if (i % prim[j] == 0)
            {
                break;
            }
        }
    }
    int m;
    int n;
    scanf("%d",&n);
    //int maxx=0;
    for (i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        int j;
        for (j=0; prim[j]<=(int)sqrt(a[i]); j++)
        {
            if (a[i]%prim[j]==0)
            {
                num[prim[j]]++;
                a[i]=a[i]/prim[j];
                while (a[i]%prim[j]==0)
                    a[i]=a[i]/prim[j];
            }
        }
        if (a[i]==1)
            continue;
        else
            num[a[i]]++;
        //maxx=max(prim[j],max(maxx,a[i]));
    }
    for (i=1; i<10000010; i++)
        num[i]+=num[i-1];
    scanf("%d",&m);
    for (i=0; i<m; i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%I64d\n",num[min(10000010-1,y)]-num[min(10000010-1,x-1)]);
    }
    return 0;
}
