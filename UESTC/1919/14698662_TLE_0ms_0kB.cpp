#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int a[100010];
int main()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if (op==1)
        {
            sort(a+x-1,a+y,cmp);
        }
        else
        {
            sort(a+x-1,a+y);
        }
    }
    printf("%d",a[k-1]);
    return 0;
}
