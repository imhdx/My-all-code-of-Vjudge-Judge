#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
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
