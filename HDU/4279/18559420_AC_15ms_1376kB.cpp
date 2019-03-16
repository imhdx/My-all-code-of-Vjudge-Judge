#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
    if (x<=5) return 0;
    int y=sqrt(double(x));
    while ((y+1)*(y+1)<=x) y++;
    while (y*y>x) y--;
    int ans=x/2-1;
    if (y%2==0) ans--;
    return ans;
}
signed main()
{
    int T;
    scanf("%lld",&T);
    while (T--){
        int a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",f(b)-f(a-1));
    }
    return 0;
}
