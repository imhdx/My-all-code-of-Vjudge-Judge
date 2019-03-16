#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main()
{
    int T;
    scanf("%d",&T);
    int t=1;
    while (T--)
    {
        memset(a,0,sizeof(a));
        int n;
        int m;
        scanf("%d",&n);
        int flag=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&m);
            if (m>=n) flag=1;
            else
                a[m]++;
        }
        if (flag==0)
        {
            for (int i=0;i<n;i++)
            {
                if (a[i]+a[n-1-i]!=2)
                {
                    flag=1;
                    break;
                }
            }
        }
        printf("Case %d: ",t++);
        if (flag==1) printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
