#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[1000];
    int n;
    scanf("%d",&n);
    getchar();
    while (n--)
    {
        gets(str);
        int ans=0;
        int len=strlen(str);
        for (int i=0;i<len;i++)
        {
            if ((int)str[i]<0) ans++;
        }
        printf("%d\n",ans/2);

    }
    return 0;
}
