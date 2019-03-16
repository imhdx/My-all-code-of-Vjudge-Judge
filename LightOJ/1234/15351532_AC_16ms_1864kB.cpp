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
typedef long long ll;
typedef unsigned long long ull;
//const double PI = acos(-1.0);
inline double Euler(int n){return log(n)+1.0/(n+n)+0.57721566490153286060651209008240243;}
const double esp=1e-8;
double a[10000];
int main()
{
    int i;
    a[1]=1.0;
    for (i=2;i<10000;i++)
        a[i]=a[i-1]+1.0/i;
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        printf("Case %d: ",t++);
        int n;
        scanf("%d",&n);
        if (n<10000) printf("%.10f\n",a[n]);
        else
        {
            double ans=Euler(n);
            printf("%.10f\n",ans);
        }
    }
    return 0;
}