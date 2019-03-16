#include<bits/stdc++.h>
using namespace std;
char str[1000];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while (n--)
    {
        int a=0,e=0,i=0,o=0,u=0;
        gets(str);
        for (int j=0;str[j];j++)
        {
            if (str[j]=='a') a++;
            if (str[j]=='e') e++;
            if (str[j]=='i') i++;
            if (str[j]=='o') o++;
            if (str[j]=='u') u++;
        }

        printf("a:%d\n",a);
        printf("e:%d\n",e);
        printf("i:%d\n",i);
        printf("o:%d\n",o);
        printf("u:%d\n",u);
        if (n!=0)
            printf("\n");
    }
    return 0;
}
