#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
int a[500005];
int b[500005];
int n;
int ans=0;
void gbsort(int l,int r)
{
    if (l>=r)
        return ;
    int mid=(l+r)/2;
    gbsort(l,mid);
    gbsort(mid+1,r);
    int x1=l,x2=mid+1;
    memset(b,0,sizeof(b));
    int cnt = 0;
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
    x1=l;
    for (int i=0; i<cnt; i++)
    {
        a[x1+i]=b[i];
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
        printf("%d\n",ans);
    }
    return 0;
}
