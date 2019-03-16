#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int a[500005];
int b[500005];
int n;
long long int ans=0;
void gbsort(int l,int r)
{
    if (l>=r)
        return ;
    int mid=(l+r)/2;
    gbsort(l,mid);
    gbsort(mid+1,r);
    int x1=l,x2=mid+1;
    int cnt = l;
    while (x1<=mid&&x2<=r)
    {
        if (a[x1]<=a[x2])
        {
            b[cnt++]=a[x1];
            x1++;
        }
        else
        {
            ans+=(mid-x1+1);
            b[cnt++]=a[x2];
            x2++;
        }
    }
    while (x1<=mid)
    {
        b[cnt++]=a[x1];
        x1++;
    }
    while (x2<=r)
    {
        b[cnt++]=a[x2];
        x2++;
    }
    for (int i=l; i<cnt; i++)
    {
        a[i]=b[i];
    }
    return ;
}

int main()
{
    int n;
    int i;
    while (scanf("%d",&n)!=EOF&&n)
    {
        for (i=0; i<n; i++)
            scanf("%d",&a[i]);
        ans=0;
        gbsort(0,n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
