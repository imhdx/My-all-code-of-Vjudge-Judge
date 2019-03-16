#include<bits/stdc++.h>
using namespace std;
int a[1000011];
int pri[10000010];
int prim[10000010];
long long int num[10000010];
int main()
{
    int i;
    int cnt=0;
    for (i=2;i<10000010;i++)
    {
        if (pri[i]==0)
        {
            prim[cnt++]=i;
            for (long long int j=i;i*j<10000010;j++)
                pri[i*j]=1;
        }
    }
    int m;
    int n;
    scanf("%d",&n);
    //int maxx=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        int j;
        for (j=0;prim[j]<=(int)sqrt(a[i]);j++)
        {
            if (a[i]%prim[j]==0)
            {
                num[prim[j]]++;
                a[i]=a[i]/prim[j];
                while (a[i]%prim[j]==0) a[i]=a[i]/prim[j];
            }
        }
        if (a[i]==1)
            continue;
        else
            num[a[i]]++;
        //maxx=max(prim[j],max(maxx,a[i]));
    }
    for (i=1;i<10000010;i++)
        num[i]+=num[i-1];
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%I64d\n",num[min(10000010-1,y)]-num[min(10000010-1,x-1)]);
    }
    return 0;
}
