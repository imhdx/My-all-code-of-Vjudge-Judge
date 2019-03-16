#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int a[200010];
const int mod=7901;
int main()
{
    int T;
    scanf("%d\n",&T);
    while (T--)
    {
        int n;
    scanf("%d",&n);
    int i,j;
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    long long ans=1;
    for (i=0;i<n;i=j)
    {
        j=i;
        while (j<n&&a[i]==a[j])
        {
            j++;
        }
        ans=ans*(j-i)%mod;
    }
    printf("%I64d\n",ans);
    }

    return 0;
}
