#include<cstdio>
#include<cstdlib>
using namespace std;
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
char str[102][102];
int n,m;
void dfs(int x,int y)
{
    for (int i=0;i<8;i++){
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx<0||tx>=n||ty<0||ty>=m) continue;
        if (str[tx][ty]=='.') continue;
        str[tx][ty]='.';
        dfs(tx,ty);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%s",str[i]);
    int cnt=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (str[i][j]=='W'){
                cnt++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
