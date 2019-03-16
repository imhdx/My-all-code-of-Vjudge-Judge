#include<bits/stdc++.h>
using namespace std;
char a[100010];
int main()
{
    while (scanf("%s",a)!=EOF)
    {
        int cnt=0;
        int i;
        for (int i=0;a[i];i++)
        {
            if (a[i]=='0')
                cnt++;
        }
        printf("%d\n",min(cnt,(int)strlen(a)-cnt));
    }
    return 0;
}
