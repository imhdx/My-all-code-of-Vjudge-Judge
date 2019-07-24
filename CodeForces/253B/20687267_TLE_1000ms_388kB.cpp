#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);

    int minn=n+1;

    int pos=0;
    for (int i=0;i<n;i++)
    {
        while (pos<n&&a[pos]<=2*a[i])
        {
            pos++;
        }
        //printf("%d %d\n",i,pos);
        if (pos-1<n&&a[pos-1]<=2*a[i])
        {
            minn=min(minn,i+n-pos);
        }
    }
    printf("%d\n",minn);

    return 0;
}