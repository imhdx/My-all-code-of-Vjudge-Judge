#include<bits/stdc++.h>
using namespace std;
int a[55];
int main()
{
    int n;
    int t=0;
    while (scanf("%d",&n)!=EOF&&n)
    {
        if (t) printf("\n");
        t=1;
        int s=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        int ans=0;
        for (int i=0;i<n;i++)
        {
            ans+=abs(a[i]-s/n);
        }
        printf("%d\n",ans/2);
    }
    return 0;
}
