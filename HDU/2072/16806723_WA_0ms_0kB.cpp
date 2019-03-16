#include<bits/stdc++.h>
using namespace std;
const double PI=4*atan(1.0);
char str[1003];
int main()
{
    while (gets(str)!=NULL)
    {
        if (str[0]=='#') return 0;
        int cnt=0;
        char c=' ';
        for (int i=0;str[i];i++)
        {
            if (c==' '&&str[i]!=c)
            {
                cnt++;
            }
            c=str[i];
        }
        printf("%d\n",cnt);
    }
    return 0;
}
