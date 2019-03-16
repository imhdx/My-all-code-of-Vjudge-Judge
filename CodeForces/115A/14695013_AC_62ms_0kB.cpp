#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    int a[2010];
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int maxx=0;
    int j;
    for (i=1;i<=n;i++)
    {
        int tmp=0;
        for (j=i;j!=-1;j=a[j])
        {
            tmp++;
        }
        maxx=max(maxx,tmp);
    }
    printf("%d\n",maxx);
    return 0;
}
