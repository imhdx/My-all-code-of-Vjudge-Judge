#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    long long r,m,y;
    scanf("%lld%lld%lld",&r,&m,&y);
    long long ans=ll(m*pow(1+r/100.0,y*1.0));
    printf("%lld\n",ans);
    return 0;
}
