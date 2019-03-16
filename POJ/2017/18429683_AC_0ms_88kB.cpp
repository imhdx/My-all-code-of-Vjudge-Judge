#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a[200];
int b[200];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==-1) return 0;
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            ans+=a[i]*(b[i]-b[i-1]);
        }
        printf("%d miles\n",ans);
    }
    return 0;
}
