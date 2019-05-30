//
// Created by mhdx on 2019/5/12.
//

#include<bits/stdc++.h>
using namespace std;
char str[120][120];
int n,m;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void dfs(int x,int y)
{
    str[x][y]='#';
    for (int i=0;i<4;i++)
    {
        if (str[x+dx[i]][y+dy[i]]=='-') dfs(x+dx[i],y+dy[i]);
    }
}
int main()
{
    int tt=1;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int ans=0;
        for (int i=0;i<n;i++) scanf("%s",str[i]);
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
                if (str[i][j]=='-') ans++,dfs(i,j);
        }
        printf("Case %d: %d\n",tt++,ans);
    }
    return 0;
}