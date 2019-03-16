#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        double a,b,c;
        scanf("%lf%lf%lf",&a,&b,&c);
        if (a>0&&b>0&&c>0)
        {
            if (a+b>c&&a+c>b&&b+c>a)
            {
                printf("YES\n");
            }
            else
                printf("NO\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}
