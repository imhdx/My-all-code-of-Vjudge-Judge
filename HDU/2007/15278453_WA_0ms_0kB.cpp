#include<bits/stdc++.h>
using namespace std;
long long int a[200000];//jishudelifanghe
long long int b[200000];
int main()
{
    int n,m;
    for (int i=1;i<200000;i++)
    {
        if (i%2==0)
        {
            a[i]=a[i-1];
            b[i]=b[i-1]+i*i;
        }
        else
        {
            b[i]=b[i-1];
            a[i]=a[i-1]+i*i*i;
        }
    }

    while (scanf("%d%d",&n,&m)!=EOF)
    {
        printf("%lld %lld\n",b[m]-b[n-1],a[m]-a[n-1]);
    }
    return 0;
}
