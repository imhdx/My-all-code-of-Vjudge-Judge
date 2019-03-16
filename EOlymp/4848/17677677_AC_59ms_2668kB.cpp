#include<bits/stdc++.h>
using namespace std;
int a[100005];
string str;
int main()
{
    int x=0;
    int cnt=0;
    getline(cin,str);
    for (int i=0;str[i];i++)
    {
        if (str[i]>='0'&&str[i<='9'])
        {
            x=x*10+str[i]-'0';
        }
        else
        {
            a[cnt++]=x;
            x=0;
        }
    }
    a[cnt++]=x;
    sort(a,a+cnt);
    for (int i=0;i<cnt;i++)
    {
        printf("%d%c",a[i]," \n"[i==cnt-1]);
    }
    return 0;
}
