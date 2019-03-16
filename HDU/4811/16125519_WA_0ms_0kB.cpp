#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a[4];
    while (scanf("%lld%lld%lld",&a[0],&a[1],&a[2])!=EOF)
    {
        long long int ans=0;
        sort(a,a+3);
        if (a[0]>=2)
        {
            ans=15ll+6ll*(a[0]+a[1]+a[2]-6);
        }
        else if (a[0]==0&&a[1]==0)
        {
            ans=a[2]-1ll;
        }
        else if (a[0]==0&&a[1]==1)
        {
            ans=1ll+(a[2]-1)*2ll;
        }
        else if (a[0]==0&&a[1]>=2)
        {
            ans=(a[1]+a[2]-4)*4ll+6ll;
        }
        else if (a[0]==1&&a[1]==1)
        {
            if (a[2]==1)
                ans=3ll;
            else if (a[2]==2)
                ans=6ll;
            else
                ans=6ll+4ll*(a[2]-2);
        }
        else if (a[0]==1&&a[1]>=2)
        {
            ans=(a[1]+a[2]-4)*5ll+10ll;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
