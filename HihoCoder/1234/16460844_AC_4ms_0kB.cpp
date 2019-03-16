#include<bits/stdc++.h>
using namespace std;
const double eps=1e-5;
int main()
{
    double f[1010];
    f[0]=0;
    f[1]=0.25;
    for (int i=2;i<1010;i++) f[i]=0.25+f[i-1]/2;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        double k;
        scanf("%lf",&k);
        int i=0;
        while (f[i]<k)
        {
            i++;
        }
        if (f[i]==k)
            printf("-1\n");
        else
            printf("%d\n",4*i);
    }
    return 0;
}
