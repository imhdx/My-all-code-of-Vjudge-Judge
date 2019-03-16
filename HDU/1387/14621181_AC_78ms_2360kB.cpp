#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
int zteam[1000000];
char str[30];
int main()
{
    int n,t,i,j,ok=1;
    while (scanf("%d",&t)!=EOF)
    {
        queue<int> team;
        queue<int> element[1010];
        int qteam[1010]={0};
        if (t==0) break;
        for (i=0;i<t;i++)
        {
            scanf("%d",&n);
            for (j=0;j<n;j++)
            {
                int qq;
                scanf("%d",&qq);
                zteam[qq]=i;
            }
        }
        printf("Scenario #%d\n",ok);
        ok++;
        getchar();
        while (scanf("%s",str)!=EOF)
        {
            if (str[0]=='S') break;
            else if (str[0]=='E')
            {
                int ele;
                scanf("%d",&ele);
                getchar();
                if (qteam[zteam[ele]]==0)
                {
                    qteam[zteam[ele]]=1;
                    team.push(zteam[ele]);
                    element[zteam[ele]].push(ele);
                }
                else
                {
                    element[zteam[ele]].push(ele);
                }
            }
            else if (str[0]=='D')
            {
                printf("%d\n",element[team.front()].front());
                element[team.front()].pop();
                if (element[team.front()].empty())
                {
                    qteam[team.front()]=0;
                    team.pop();
                }
            }
        }
        printf("\n");
    }
    return 0;
}