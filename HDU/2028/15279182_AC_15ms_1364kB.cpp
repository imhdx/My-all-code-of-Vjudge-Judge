#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if (y==0) return x;
    return gcd(y,x%y);
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ans=1;
        int i;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            ans=ans/gcd(ans,x)*x;
        }
        printf("%d\n",ans);
    }

    return 0;
}
