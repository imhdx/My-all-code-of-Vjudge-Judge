#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    int a[20];
    while (t--)
    {
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",a[1]);
    }
    return 0;
}
