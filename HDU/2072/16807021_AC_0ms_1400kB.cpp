#include<bits/stdc++.h>
using namespace std;
const double PI=4*atan(1.0);
char str[1003];
int main()
{
    set<string> s;
    string str="";
    char c;
    while (scanf("%c",&c)!=EOF)
    {
        if (c=='#') return 0;
        else if (c==' ')
        {
            if (str.length())
            {
                s.insert(str);
                str="";
            }
        }
        else if (c=='\n')
        {
            if (str.length())
            {
                s.insert(str);
                str="";
            }
            printf("%d\n",s.size());
            s.clear();
        }
        else
            str+=c;
    }
    return 0;
}
