#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long a[10004];
int main()
{
    int cnt=1;
    for (int i=1;i<=1000;i++)
    {
        for (int j=1;j<=i&&cnt<10004;j++) a[cnt++]=a[cnt-2]+i;
    }
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        printf("%d %I64d\n",n,a[n]);
    }
    return 0;
}
