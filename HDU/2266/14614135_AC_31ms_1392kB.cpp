#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char str[15];
long long int n;
long long int cnt=0;
int m;
void dfs(int num,long long int s)
{
    if (num==m)
    {
        if (s==n)
        {
            cnt++;
            return ;
        }
        return ;
    }
    int tmp=0;
    for (int i=num;i<m;i++)
    {
        tmp=tmp*10+(str[i]-'0');
        dfs(i+1,s+tmp);
        if (num)
            dfs(i+1,s-tmp);
    }
}

int main()
{
    while (cin>>str>>n)
    {
        m=strlen(str);
        cnt=0;
        dfs(0,0);
        cout<<cnt<<endl;
    }
    return 0;
}
