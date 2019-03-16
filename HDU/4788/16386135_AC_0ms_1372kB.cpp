#include<bits/stdc++.h>
using namespace std;
char str[1200];
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",str);
        int i;
        for (i=0;str[i];i++)
        {
            if (str[i]=='[')
                break;
        }
        i++;
        double a=1000/1024.0;
        double ans=0;
        switch (str[i])
        {
        case 'B':ans=1-1;break;
        case 'K':ans=1.0-a;break;
        case 'M':ans=1.0-a*a;break;
        case 'G':ans=1.0-a*a*a;break;
        case 'T':ans=1.0-a*a*a*a;break;
        case 'P':ans=1-a*a*a*a*a;break;
        case 'E':ans=1-a*a*a*a*a*a;break;
        case 'Z':ans=1-a*a*a*a*a*a*a;break;
        case 'Y':ans=1-a*a*a*a*a*a*a*a;break;
        }
        printf("Case #%d: ",t++);
        printf("%.2f%%\n",ans*100);
    }
    return 0;
}
