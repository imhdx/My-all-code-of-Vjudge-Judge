#include<bits/stdc++.h>
using namespace std;
char str[505][2002];
int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%s",str[i]);
        int i;
        int j;
        for (i=n;i>=1;i--)
        {
            for (j=0;j<i;j++)
            {
                if (!strstr(str[i],str[j]))
                {
                    break;
                }
            }
            if (j<i)
            {
                break;
            }
        }
        printf("Case #%d: ",t++);
        if (i>=1)
            printf("%d\n",i);
        else
            printf("-1\n");
    }
    return 0;
}
