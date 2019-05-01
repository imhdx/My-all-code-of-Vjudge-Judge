#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y;
}p[502];
bool vis[220][220];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        for (int i=0;i<n;i++)scanf("%d%d",&p[i].x,&p[i].y);
        for (int i=0;i<n;i++)
        {
            vis[p[i].x+100][p[i].y+100]=1;
        }
        long long cnt=0;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i==j) continue;
                int tmpx=p[i].x+p[j].y-p[i].y;
                int tmpy=p[i].y+p[i].x-p[j].x;
                //printf("%d %d\n",tmpx,tmpy);
                if (tmpx+100>=0&&tmpx+100<220&&tmpy+100>=0&&tmpy+100<220&&
                    vis[tmpx+100][tmpy+100])
                {
                    tmpx=p[j].x+p[j].y-p[i].y;
                    tmpy=p[j].y+p[i].x-p[j].x;
                    if (tmpx+100>=0&&tmpx+100<220&&tmpy+100>=0&&tmpy+100<220&&vis[tmpx+100][tmpy+100]) cnt++;
                }

                tmpx=p[i].x-(p[i].y-p[j].y);
                tmpy=p[i].y-(p[j].x-p[i].x);
                //printf("%d %d\n",tmpx,tmpy);
                if (tmpx+100>=0&&tmpx+100<220&&tmpy+100>=0&&tmpy+100<220&&vis[tmpx+100][tmpy+100])
                {
                    tmpx=p[j].x-(p[i].y-p[j].y);
                    tmpy=p[j].y-(p[j].x-p[i].x);
                    if (tmpx+100>=0&&tmpx+100<220&&tmpy+100>=0&&tmpy+100<220&&vis[tmpx+100][tmpy+100]) cnt++;
                }


            }
        }
        printf("%lld\n",cnt/8);

    }
    return 0;
}
//