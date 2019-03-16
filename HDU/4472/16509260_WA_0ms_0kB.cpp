#include<bits/stdc++.h>
using namespace std;
long long a[1002];
int t=1;
int main()
{
    int n;
    a[0]=0;
    a[1]=1;
    a[2]=1;
    a[3]=2;
    for (int i=4;i<=1000;i++)
    {
        for (int j=1;j<=i-1;j++)
        {
            if ((i-1)%j==0)
                a[i]+=a[j];
        }

    }

    while (scanf("%d",&n)!=EOF)
    {
        printf("Case %d: ",t++);
        printf("%lld\n",a[n]);
    }
    return 0;
}
