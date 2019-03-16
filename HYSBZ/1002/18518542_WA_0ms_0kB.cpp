#include<bits/stdc++.h>
using namespace std;
long double ans[10];
int main()
{
    int n;scanf("%d",&n);
    ans[1]=1;
    ans[2]=5;
    ans[3]=16;
    for (int i=4;i<=n;i++)
    {
        ans[4]=ans[3]*3-ans[2]+2;
        //printf("%.0lf\n",ans[4]);
            for (int j=1;j<=3;j++) ans[j]=ans[j+1];
    }
    if (n<=3) printf("%.0lf\n",ans[n]);
    else printf("%.0lf\n",ans[4]);
    return 0;
}
