#include<cstdio>
using namespace std;
int pre[10100];
int dx[]={0,0,1,-1,1,1,-1,-1};
int dy[]={-1,1,0,0,-1,1,1,-1};
int getx(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=getx(pre[x]);
}
void nian(int x,int y)
{
    x=getx(x);
    y=getx(y);
    if (x!=y) pre[x]=y;
}
char str[102][102];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%s",str[i]);
    for (int i=0;i<n*m;i++) pre[i]=i;
    int sum=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (str[i][j]=='W'){
                sum++;
            for (int k=0;k<8;k++){
                int xx=i+dx[k];
                int yy=j+dy[k];
                if (xx<0||xx>=n||yy<0||yy>=m) continue;
                if (str[xx][yy]=='W') nian(i*m+j,xx*m+yy);
            }
            }
        }
    }
    int cnt=0;
    for (int i=0;i<n*m;i++){

        if (getx(i)==i) cnt++;
    }
    printf("%d\n",cnt-(n*m-sum));
    return 0;
}
