#include<bits/stdc++.h>
using namespace std;
int sum[500002];
int main()
{
    int i,j;
    for (i=2;i<500002;i++)
        sum[i]=1;
    for (i=2;i<500002;i++)
    {
            for (j=1;1ll*i*j<500002;j++)
            {
                if (i*j>i) sum[i*j]+=i;
            }
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x;
        scanf("%d",&x);
        int ans=sum[x];
        printf("%d\n",ans);
    }

    return 0;
}
