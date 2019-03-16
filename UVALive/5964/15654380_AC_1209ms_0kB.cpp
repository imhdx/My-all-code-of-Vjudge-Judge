#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull gcd(ull a,ull b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
ull lcm(ull a,ull b)
{
    return a/gcd(a,b)*b;
}
ull euler[5000010];
ull ans[5000010];
void getEuler()
{
    euler[1]=1;
    for (int i=2;i<5000010;i++)
    {
        if (!euler[i])
            for (int j=i;j<5000010;j+=i)
            {
                if (!euler[j])
                    euler[j]=j;
                euler[j]=euler[j]/i*(i-1);
            }
        for (int j=i;j<5000010;j+=i)
        {
            ans[j]+=1ull*(i)*euler[i]/2*j;
        }
    }
    for (int i=2;i<5000010;i++)
    {
        ans[i]+=ans[i-1];
    }
}
int main()
{
    int t=1;
    getEuler();
    // for (int i=1;i<10;i++)
    //    printf("%llu%c",ans[i]," \n"[i==9]);
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        printf("Case %d: ",t++);
        printf("%llu\n",ans[n]);
    }
    return 0;
}
