#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[1000];
    while (scanf("%s",str)!=EOF)
    {
        char c=0;
        for (int i=0;str[i];i++)
        {
            c=max(c,str[i]);
        }
        for (int i=0;str[i];i++)
        {
            printf("%c",str[i]);
            if (str[i]==c)
                printf("(max)");
        }
        printf("\n");
    }
    return 0;
}
