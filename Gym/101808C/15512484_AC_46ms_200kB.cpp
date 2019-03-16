#include<bits/stdc++.h>
using namespace std;
char a[100010];
char b[100010];
int main()
{
    int n;
    scanf("%d",&n);
    //getchar();
    while (n--)
    {
        scanf("%s",a);
        //printf("%s\n",a);
        scanf("%s",b);
        //printf("%s\n",b);
        int i,j;
        int len=strlen(a);
        int flag=0;
        int cnt=0;
        int tt=0;
        for (i=0;i<len&&i<len-i-1;i++)
        {
            if (a[i]==b[i]&&a[len-i-1]==b[len-i-1])
            {
                if (a[i]!=a[len-i-1])
                    if (tt==0)
                    {
                        continue;
                    }
                    else
                    {
                        cnt++;
                        tt=0;

                    }
                else
                {
                    continue;
                }
            }
            else if (a[i]==b[len-i-1]&&b[i]==a[len-i-1])
            {
                if (a[i]!=b[i])
                    if (tt==0)
                    {
                        cnt++;
                        tt=1;
                    }
                    else
                    {
                        continue;
                    }
                else
                continue;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if (flag==0)
        {
            if (a[i]==b[i])
                printf("%d\n",cnt);
            else
                printf("-1\n");
        }
        else
            printf("-1\n");
    }
    return 0;
}
