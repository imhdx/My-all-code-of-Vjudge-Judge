#include<bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int a[300][300];
bool p[11][3][3]={
        0,1,0,
        1,1,0,
        0,0,0,

        0,1,0,
        0,1,1,
        0,0,0,

        0,0,0,
        1,1,0,
        0,1,0,

        0,0,0,
        0,1,1,
        0,1,0,

        0,1,0,
        0,1,0,
        0,1,0,

        0,0,0,
        1,1,1,
        0,0,0,

        0,1,0,
        1,1,1,
        0,0,0,

        0,1,0,
        1,1,0,
        0,1,0,

        0,0,0,
        1,1,1,
        0,1,0,

        0,1,0,
        0,1,1,
        0,1,0,

        0,1,0,
        1,1,1,
        0,1,0
};
void bian(int x,int y,int c)
{
    x=3*x;
    y=3*y;
    int i,j,k;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
        {
            a[i+x][j+y]=p[c][i][j];
        }
    }
}
int n,m;
void dfs(int x,int y)
{
    for (int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if (xx<0||xx>=n||yy<0||yy>=m) continue;
        if (a[xx][yy]==1)
        {
            a[xx][yy]=0;
            dfs(xx,yy);
        }
    }
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==-1&&m==-1) break;
        getchar();
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                char c;
                int cc;
                while (!((c=getchar())&&c>='A'&&c<='Z')) ;
                    cc=c-'A';
                bian(i,j,cc);
            }
        }
        /*
        for (i=0;i<3*n;i++)
        {
            for (j=0;j<3*m;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
        */
        n=3*n;
        m=3*m;
        int cnt=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (a[i][j]==1)
                {
                    a[i][j]=0;
                    cnt++;
                    dfs(i,j);
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
