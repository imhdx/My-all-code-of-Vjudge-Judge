#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        int cnt=0;
        long long ans=0;
        for (int i=1;;i++)
        {
            for (int j=1;j<=i;j++)
            {
                ans+=i;
                cnt++;
                if (cnt==n) break;
            }
            if (cnt==n) break;
        }
        printf("%d %lld\n",n,ans);
    }

    return 0;
}
