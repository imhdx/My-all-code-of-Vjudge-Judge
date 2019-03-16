#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[300];
    scanf("%s",str);
    printf("%d ",strlen(str));
    int x=0;
    int y=0;
    for (int i=0;str[i];i++)
    {
        x=x*2;
        y=y*2;
        if (str[i]=='1') x++;
        else if (str[i]=='2') y++;
        else if (str[i]=='3')
        {
            x++;
            y++;
        }
    }
    printf("%d %d\n",x,y);
    return 0;
}
