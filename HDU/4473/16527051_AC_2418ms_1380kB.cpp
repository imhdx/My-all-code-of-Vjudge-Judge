#include<bits/stdc++.h>
using namespace std;
long long pow2(long long x)
{
    long long y=pow(x,0.5);
    while (y*y>x) y--;
    while ((y+1)*(y+1)<=x) y++;
    return y;
}
long long pow3(long long x)
{
    long long y=pow(x,1.0/3);
    while (y*y*y>x) y--;
    while ((y+1)*(y+1)*(y+1)<=x) y++;
    return y;
}
int main()
{
    long long n;
    int t=1;
    while (scanf("%lld",&n)!=EOF)
    {
        long long ans=0;
        for (long long i=1;i*i*i<=n;i++)
        {
            for (long long j=i;i*j*j<=n;j++)
            {
                if (i==j)
                {
                    ans++;
                    if (n/(i*j)>j)
                    ans+=3*(n/(i*j)-j);
                }
                else
                {
                    ans+=3;
                    ans+=6*(n/(i*j)-j);
                }

            }
        }
        printf("Case %d: ",t++);
        printf("%lld\n",ans);
    }
    return 0;
}
