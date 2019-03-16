#include<bits/stdc++.h>
using namespace std;
int n,m;
const int INF=0x3f3f3f3f;
int ma[10][10];
int k;
vector<pair<int,int> > v;
int dis[120][120];
struct node
{
    int x;
    int y;
    int s;
}que[10205];
int tx[]={0,1,0,-1};
int ty[]={1,0,-1,0};
bool vis[120][120];
char str[120][120];
int mei[10];
void bfs(int stx,int sty)
{
    int tou=0,wei=0;
    que[wei].x=stx;
    que[wei].y=sty;
    que[wei].s=0;
    vis[stx][sty]=1;
    dis[stx][sty]=0;
    wei++;
    while (tou<wei)
    {
        for (int i=0;i<4;i++)
        {
            int dx=que[tou].x+tx[i];
            int dy=que[tou].y+ty[i];
            if (dx<0||dx>=n||dy<0||dy>=m||vis[dx][dy]||str[dx][dy]=='#') continue;
            vis[dx][dy]=1;
            que[wei].x=dx;
            que[wei].y=dy;
            que[wei].s=que[tou].s+1;
            dis[dx][dy]=que[wei].s;
            wei++;
        }
        tou++;
    }
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) return 0;
        v.clear();
        for (int i=0;i<n;i++)
            scanf("%s",str[i]);
        scanf("%d",&k);
        memset(vis,0,sizeof(vis));
        memset(dis,0x3f,sizeof(dis));
        for (int i=0;i<n;i++)
        {
            int j;
            for (j=0;j<m;j++)
            {
                if (str[i][j]=='@')
                {
                    bfs(i,j);
                    break;
                }
            }
            if (j<m) break;
        }
        for (int i=0;i<k;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            v.push_back({x,y});
        }
        for (int i=0;i<k;i++)
        {
            ma[k][i]=dis[v[i].first][v[i].second];
            ma[i][k]=dis[v[i].first][v[i].second];
        }
        for (int i=0;i<k;i++)
        {
            memset(vis,0,sizeof(vis));
            memset(dis,0x3f,sizeof(dis));
            bfs(v[i].first,v[i].second);
            for (int j=0;j<k;j++)
            {
                ma[i][j]=dis[v[j].first][v[j].second];
                ma[j][i]=dis[v[j].first][v[j].second];
            }
        }
        for (int i=0;i<k;i++)
        mei[i]=i;
        int cnt=INF;
        do
        {
            if (ma[k][mei[0]]==INF) continue;
            int bu=ma[k][mei[0]];
            int i;
            for (i=1;i<k;i++)
            {
                if (ma[i-1][i]==INF) break;
                bu+=ma[i-1][i];
            }
            if (i<k) continue;
            cnt=min(cnt,bu);
        }while (next_permutation(mei,mei+k));
        if (cnt>=INF) printf("-1\n");
        else
        printf("%d\n",cnt);

    }

    return 0;
}
