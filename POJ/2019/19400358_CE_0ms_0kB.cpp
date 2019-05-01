#include<bits/stdc++.h>
using namespace std;
int a[252][252];
int lo[252];
int st1[252][252][9][9];///最大值
int st2[252][252][9][9];///最小值
int n,m;
void rmq()
{
    lo[1]=0;for (int i=2;i<252;i++) lo[i]=lo[i/2]+1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            st1[i][j][0][0]=st2[i][j][0][0]=a[i][j];
    for (int ii=0;ii<=lo[n];ii++)
    {
        for (int jj=0;jj<=lo[m];jj++)
        {
            if (ii+jj)
            {
                for (int i=1;i+(1<<ii)-1<=n;i++)
                {
                    for (int j=1;j+(1<<jj)-1<=m;j++)
                    {
                        if(ii)
                        {
                            st1[i][j][ii][jj] = max(st1[i][j][ii-1][jj],st1[i+(1<<(ii-1))][j][ii-1][jj]);
                            st2[i][j][ii][jj] = min(st2[i][j][ii-1][jj],st2[i+(1<<(ii-1))][j][ii-1][jj]);
                        }
                        else
                        {
                            st1[i][j][ii][jj] = max(st1[i][j][ii][jj-1],st1[i][j+(1<<(jj-1))][ii][jj-1]);
                            st2[i][j][ii][jj] = min(st2[i][j][ii][jj-1],st2[i][j+(1<<(jj-1))][ii][jj-1]);
                        }
                    }
                }
            }
        }
    }
}
pair<int,int> ask(int x1,int y1,int x2,int y2)
{
    int k1=lo[x2-x1+1];
    int k2=lo[y2-y1+1];
    x2=x2-(1<<k1)+1;
    y2=y2-(1<<k2)+1;
    return make_pair(
    max(max(st1[x1][y1][k1][k2],st1[x1][y2][k1][k2]),
        max(st1[x2][y1][k1][k2],st1[x2][y2][k1][k2])),
    min(min(st2[x1][y1][k1][k2],st2[x1][y2][k1][k2]),
        min(st2[x2][y1][k1][k2],st2[x2][y2][k1][k2]))
    );
}
int main()
{
    int k,b;
    scanf("%d%d%d",&n,&b,&k);
    m=n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    rmq();
    while (k--)
    {
        int x,y;scanf("%d%d",&x,&y);
        pair<int,int> ans=ask(x,y,x+b-1,y+b-1);
        printf("%d\n",ans.first-ans.second);
    }
    return 0;
}
