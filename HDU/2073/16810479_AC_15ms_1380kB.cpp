#include<bits/stdc++.h>
using namespace std;
double ans[666];
int main()
{
    ans[0]=0;
    ans[1]=1;
    for (int i=2;i<666;i++)
    {
        ans[i]=ans[i-1]+sqrt(2)*(i-1)+sqrt(i*i+(i-1)*(i-1));
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        double k=fabs(ans[x1+y1]+x1*sqrt(2)-ans[x2+y2]-x2*sqrt(2));
        printf("%.3f\n",k);
    }
    return 0;
}
