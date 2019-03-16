#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        long long int a,b;
        scanf("%lld%lld",&a,&b);
        if (a*a>2*b*b)
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
