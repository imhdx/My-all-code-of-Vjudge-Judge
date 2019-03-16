#include<cstdio>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
vector<int>v[30];
int vis[30];
int flag=0;
void dfs(int num)
{
    if (flag==1)
        return ;
    if (num=='m'-'a')
    {
        flag=1;
        return ;
    }
    for (int i=0; i!=v[num].size(); i++)
    {
        if (vis[v[num][i]])
            continue;
        vis[v[num][i]]=1;
        dfs(v[num][i]);
        vis[v[num][i]]=0;
        if (flag==1)
            return ;
    }
}
int main()
{
    string str;
    while (cin>>str)
    {
        flag=0;
        if (str=="0")
            continue;
        for (int i=0; i<30; i++)
        v[i].clear();
        memset(vis,0,sizeof(vis));
        v[str[0]-'a'].push_back(str[str.size()-1]-'a');
        while (cin>>str)
        {
            if (str=="0")
                break;
            v[str[0]-'a'].push_back(str[str.size()-1]-'a');
        }
        if (v['b'-'a'].size()==0)
            printf("No.\n");
        else
        {
            vis['b'-'a']=1;
            dfs('b'-'a');
            if (flag==0)
                printf("No.\n");
            else
                printf("Yes.\n");
        }
    }
    return 0;
}
