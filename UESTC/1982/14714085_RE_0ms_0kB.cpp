#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[100005];
void print(int k)
{
    int len=s[k].size();
    for (int i=0;i<len;i++)
    {
        if (s[k][i]>='a'&&s[k][i]<='z'||s[k][i]>='A'&&s[k][i]<='Z')
            cout<<s[k][i];
        if (s[k][i]>='0'&&s[k][i]<='9')
        {
            if (k-s[k][i]+'0'<0) continue;
            else        print(k-s[k][i]+'0');
        }
    }
}
string str;
int main()
{
    int i;
    cin>>str;
    int len=str.size();
    for (i=len-1;i>=0;)
    {
        if (str[i]=='#')
        {
            while (i>=0&&str[i]!=';')
            {
                str[i]='#';
                i--;
            }
        }
        else if (str[i]=='@')
        {
            str[i]='#';
            i--;
        }
        else i--;
    }
    int cnt=0;
    for (i=0;i<100005;i++)
        s[i]="";
    for (i=0;i<len;i++)
    {
        if (str[i]!=';')
        s[cnt]=s[cnt]+str[i];
        else
        {
            s[cnt]=s[cnt]+'\0';
            cnt++;
        }
    }
    if (str[len-1]!=';')
    {
        s[cnt]=s[cnt]+'\0';
        cnt++;
    }
    for (i=0;i<cnt;i++)
    {
        print(i);
        if (i==cnt-1&&str[len-1]!=';');
        else
            cout<<endl;
    }
    return 0;
}
