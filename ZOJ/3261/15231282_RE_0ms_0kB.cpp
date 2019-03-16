#include<bits/stdc++.h>
char str[10];
using namespace std;
vector<int> v[10010];
int a[10010];
bool cmp(int x,int y)
{
    if (a[x]==a[y])
        return x<y;
    return a[x]>a[y];
}
int vis[10010][10010];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        for (i=0;i<10010;i++) v[i].clear();
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            for (j=0;j<n;j++)
                vis[i][j]=0;
        }
        int m;
        scanf("%d",&m);
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            vis[x][y]=vis[y][x]=1;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for (i=0;i<n;i++)
        {
            sort(v[i].begin(),v[i].end(),cmp);
        }
        scanf("%d",&m);
        for (i=0;i<m;i++)
        {
            getchar();
            scanf("%s",str);
            if (str[0]=='q')
            {
                int x;
                int flag=0;
                scanf("%d",&x);
                for (j=0;j<v[x].size();j++)
                {
                    if (a[v[x][j]]<=a[x])
                    {
                        break;
                    }
                    else
                    {
                        if (vis[x][v[x][j]])
                        {
                            flag=1;
                            break;
                        }
                    }
                }
                if (flag==0)
                    printf("-1\n");
                else
                    printf("%d\n",v[x][j]);
            }
            else if (str[0]=='d')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                vis[x][y]=vis[y][x]=0;
            }
        }
    }
    return 0;
}
