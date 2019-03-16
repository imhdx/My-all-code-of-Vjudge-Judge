#include<bits/stdc++.h>
using namespace std;

string str;
int len;
int solve(int p)
{
    while (str[p]!=')'&&p<len)
    {
        int t=0;
        while (str[p]>='0'&&str[p]<='9')
            t=t*10+str[p++]-'0';
        if (t==0) t++;
        int x=-1;
        while (t--)
        {
            if (str[p]=='(')
                x=solve(p+1);
            else
                printf("%c",str[p]);
        }
        if (x!=-1)
            p=x;
        p++;
    }
    return p;
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        cin>>str;
        len=str.length();
        solve(0);
        printf("\n");
    }
    return 0;
}
