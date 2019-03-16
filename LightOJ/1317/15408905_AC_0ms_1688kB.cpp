#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<stack>
#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int t=1;
int main()
{
    t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        printf("Case %d: ",t++);
        int n,m,k;
        double p;
        scanf("%d%d%d%lf",&n,&m,&k,&p);
        double ans=n*k*p;
        printf("%.10f\n",ans);
    }
    return 0;
}
