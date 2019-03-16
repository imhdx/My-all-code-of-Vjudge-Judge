#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int t=1;
    while (T--)
    {
        long long int n;
        scanf("%lld",&n);
        printf("Case %d: ",t++);
        long long int ans=n-(long long)sqrt(n)-(long long)sqrt(n/2.0);
        printf("%lld\n",ans);
    }
    return 0;
}
