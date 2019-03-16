#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int v[10];
int len;
bool check(char c)
{
    if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
        return true;;
    return false;
}
bool check1()
{
    int i;
    for (i=0;i<len;i++)
    {
        if (check(s[i]))
            return true;
    }
    return false;
}
bool check2()
{
    int i;
    for (i=2;i<len;i++)
    {
        if (check(s[i])&&check(s[i-1])&&check(s[i-2]))
            return false;
        if ((!check(s[i]))&&(!check(s[i-1]))&&(!check(s[i-2])))
            return false;
    }
    return true;
}
bool check3()
{
    int i;
    for (i=1;i<len;i++)
    {
        if (s[i]==s[i-1])
        {
            if (s[i]!='e'&&s[i]!='0') return false;
        }
    }
    return true;
}
int main()
{
    while (scanf("%s",s)!=EOF)
    {
        if (strcmp(s,"end")==0) return 0;
        memset(v,0,sizeof(v));
        len=strlen(s);
        int i,j;
        printf("<%s>",s);
        if (check1()&&check2()&&check3())
            printf(" is acceptable.\n");
        else
            printf(" is not acceptable.\n");
    }
    return 0;
}
