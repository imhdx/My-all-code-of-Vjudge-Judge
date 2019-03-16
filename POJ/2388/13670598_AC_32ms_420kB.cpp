#include<cstdio>
#include<algorithm>
using namespace std;
int a[10010];
int main()
{
    int n;
    int i;
    while (scanf("%d",&n)!=EOF)
    {
        int i;
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",a[(n-1)/2]);
    }
    return 0;
}
