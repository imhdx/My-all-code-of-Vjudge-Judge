#include<bits/stdc++.h>
using namespace std;
int main()
{
    int kk=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        double ans=0;
        for (int i=0;i<=n;i++)
        {
            double x;
            scanf("%lf",&x);
            ans+=x;
        }
        double mx=0;
        for (int i=0;i<n;i++)
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            mx=max(mx,y);
        }
        printf("Case #%d: %f\n",kk++,ans+mx);
    }
    return 0;
}
