#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;scanf("%d",&n);
    n++;
    long double ans=1;
    for (int i=0;i<n-2;i++)
        ans*=n;
    printf("%.0lf\n",ans);
    return 0;
}
