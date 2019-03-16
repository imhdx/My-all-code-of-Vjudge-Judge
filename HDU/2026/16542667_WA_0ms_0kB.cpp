#include<bits/stdc++.h>
using namespace std;
int main()
{
    char str[1000];
    while (gets(str)!=NULL)
    {
        if (str[0]>='a'&&str[0]<='z')
            str[0]=str[0]-'a'+'A';
        puts(str);
    }
    return 0;
}
