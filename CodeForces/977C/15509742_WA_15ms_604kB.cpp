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
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int i,j;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    if (k<n&&a[k-1]==a[k])
        printf("-1\n");
    else
        printf("%d\n",a[k-1]);
    return 0;
}
