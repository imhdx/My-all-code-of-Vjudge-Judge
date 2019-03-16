#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
int zteam[1000000];
char str[99];
int qteam[9999];
queue<int> team;
queue<int> element[9999];
int main()
{
    int t;
    int i,j;
    int ok=1;
    while (scanf("%d",&t)!=EOF)
    {
        if (t==0) break;
        int n;
        for (i=0;i<1000000;i++) zteam[i]=-1;
        for (i=0;i<9999;i++) qteam[i]=0;
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
            if (str[0]=='E')
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
            else
                break;
        }
        printf("\n");
    }
    return 0;
}
