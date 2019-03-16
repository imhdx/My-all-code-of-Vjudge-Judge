#include<bits/stdc++.h>
using namespace std;
char str[100];
int main()
{
    int T;
    int t=1;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",str);
        int i;
        for (i=0;str[i];i++)
        {
            if (str[i]>='0'&&str[i]<='9')
            {

            }
            else break;
        }
        printf("Case #%d: ",t++);
        if (str[i+1]=='B')
        {
            printf("0.00%\n");
        }
        else if (str[i+1]=='K')
        {
            printf("2.34%\n");
        }
        else if (str[i+1]=='M')
        {
            printf("4.63%\n");
        }
        else if (str[i+1]=='G')
        {
            printf("99.91%\n");
        }
        else
        {
            printf("100.00%\n");
        }
    }
    return 0;
}
