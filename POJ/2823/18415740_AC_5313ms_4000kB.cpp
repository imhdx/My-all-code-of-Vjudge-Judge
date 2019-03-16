#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e6+7;
int q[maxn];///记录队列的值在原数组中的下标
int a[maxn];///原数列
int n,k;
void getmin()
{
    int head=0,tail=-1;
    for (int i=1;i<k;i++)
    {
        while (head<=tail&&a[q[tail]]>=a[i]) tail--;
        q[++tail]=i;
    }
    for (int i=k;i<=n;i++)
    {
        while (head<=tail&&a[q[tail]]>=a[i]) tail--;
        q[++tail]=i;
        while (q[head]<=i-k) head++;
        printf("%d ",a[q[head]]);
    }
}
void getmax()
{
    int head=0,tail=-1;
    for (int i=1;i<k;i++)
    {
        while (head<=tail&&a[q[tail]]<=a[i]) tail--;
        q[++tail]=i;
    }
    for (int i=k;i<=n;i++)
    {
        while (head<=tail&&a[q[tail]]<=a[i]) tail--;
        q[++tail]=i;
        while (q[head]<=i-k) head++;
        printf("%d ",a[q[head]]);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    getmin();
    printf("\n");
    getmax();
    printf("\n");
    return 0;
}
