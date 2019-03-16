#include<bits/stdc++.h>
using namespace std;
char str[210][210];
bool vis[210][210];
const int INF=0x3f3f3f3f;
vector<pair<int,int> > v;
int dx[]= {1,1,-1,-1};
int dy[]= {1,-1,-1,1};
int bing[20];
map<pair<int,int>,int> M;
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        if (n==0&&m==0) return 0;
        M.clear();
        v.clear();
        if (n==0&&m==0)
            return 0;
        for (int i=0; i<n; i++)
            scanf("%s",str[i]);
        int d=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                if (str[i][j]=='.')
                {
                    v.push_back({i,j});
                    d++;
                    M[{i,j}]=d-1;
                }
            }
        }
        if (d==0)
        {
            printf("0\n");
            continue;
        }
        int cnt=INF;
        for (int f=0; f<4; f++)
            for (int i=0; i<d; i++)
            {
                int cc=0;
                int vx=v[i].first,vy=v[i].second;
                if (vx+dx[f]>=0&&vx+dx[f]<n&&str[vx+dx[f]][vy]=='#'||vy+dy[f]<m&&vy+dy[f]>=0&&str[vx][vy+dy[f]]=='#')
                {

                    continue;
                }
                else
                {
                    for (int p=(1<<d)-1; p>=0; p--)
                    {
                        int cc=0;
                        int ding=0;
                        memset(bing,0,sizeof(bing));
                        int vx=v[i].first,vy=v[i].second;
                        if (vx+dx[f]<n&&vx+dx[f]>=0&&bing[M[ {vx+dx[f],vy}]]==0)
                            bing[M[ {vx+dx[f],vy}]]=1,cc++;
                        if (vy+dy[f]<m&&vy+dy[f]>=0&&bing[M[ {vx,vy+dy[f]}]]==0)
                            bing[M[ {vx,vy+dy[f]}]]=1,cc++;
                        if (bing[M[ {vx,vy}]]==0)
                            bing[M[ {vx,vy}]]=1,cc++;
                        int j;
                        for (j=0; j<d; j++)
                        {
                            if ((p>>j)&1)
                            {
                                if (j==i) continue;
                                int vx=v[j].first,vy=v[j].second;
                                if (vx-1>=0&&str[vx-1][vy]=='#'||vy+1<m&&str[vx][vy+1]=='#')
                                    continue;
                                else
                                {
                                    ding++;
                                    if (vx-1>=0&&bing[M[ {vx-1,vy}]]==0)
                                        bing[M[ {vx-1,vy}]]=1,cc++;
                                    if (vy+1<m&&bing[M[ {vx,vy+1}]]==0)
                                        bing[M[ {vx,vy+1}]]=1,cc++;
                                    if (bing[M[ {vx,vy}]]==0)
                                        bing[M[ {vx,vy}]]=1,cc++;
                                }

                            }
                        }
                        if (cc==d)
                        {
                            cnt=min(cnt,ding+1);
                        }
                    }
                }
            }
        if (cnt>=INF)
            printf("-1\n");
        else
            printf("%d\n",cnt);

    }
    return 0;
}
