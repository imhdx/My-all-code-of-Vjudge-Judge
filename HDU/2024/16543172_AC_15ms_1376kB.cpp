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
        int flag=0;
        if (str[0]>='0'&&str[0]<='9') flag=1;
        for (int i=0;str[i];i++)
        {
            if (str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'||str[i]=='_'||str[i]>='0'&&str[i]<='9');
            else
                flag=1;
        }
        if (flag==0)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
