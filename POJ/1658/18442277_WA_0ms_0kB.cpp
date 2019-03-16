#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a[10];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=0;i<4;i++) scanf("%d",&a[i]);
        if (a[0]+a[1]==2*a[1]&&a[1]+a[3]==2*a[2]) a[4]=2*a[3]-a[2];
        else a[4]=a[3]*a[3]/a[2];
        for (int i=0;i<5;i++)
            printf("%d%c",a[i]," \n"[i==4]);
    }
    return 0;
}
