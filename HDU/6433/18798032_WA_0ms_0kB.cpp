#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        long double ans=1;
        for (int i=0;i<n;i++)
        {
            ans*=2;
        }
        printf("%.0lf\n",ans);
    }
    return 0;
}
