#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int tmp=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x==25)
        {
            tmp+=25;
        }
        else
        {
            if (x-25>tmp)
            {
                printf("NO\n");
                return 0;
            }
            else tmp-=(x-25);
        }
    }
    printf("YES\n");
    return 0;
}
