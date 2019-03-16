#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;
int a[52][52];
int pre[52];
struct note
{
    int len;
    int from;
    int to;
}que[2510];
bool cmp(struct note a,struct note b)
{
    return a.len<b.len;
}
int get(int x)
{
    if (pre[x]==x) return x;
    return pre[x]=get(pre[x]);
}
bool jie(int a,int b)
{
    int x=get(a);
    int y=get(b);
    if (x==y) return false;
    if (x>y) pre[x]=y;
    else
        pre[y]=x;
    return true;
}
int main()
{
    int n,m;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) break;
        scanf("%d",&m);
        if (m==0) {printf("0\n");continue;}
        int i,j;
        for (i=0;i<52;i++)
            for (j=0;j<52;j++)
                a[i][j]=200;
        for (i=0;i<m;i++)
        {
            int x,y,l;
            scanf("%d%d%d",&x,&y,&l);
            if (x<y) a[x][y]=min(a[x][y],l);
            else
                a[y][x]=min(a[y][x],l);
        }
        for (i=0;i<52;i++) pre[i]=i;
        int k=0;
        for (i=1;i<=n;i++)
        {
            for (j=i+1;j<=n;j++)
            {
                if (a[i][j]!=200)
                {
                    que[k].from=i;
                    que[k].to=j;
                    que[k].len=a[i][j];
                    k++;
                }
            }
        }

        sort(que,que+k,cmp);
        int ans=0;
        int cc=0;
        for (i=0;i<k;i++)
        {
            if (jie(que[i].from,que[i].to)) {cc++;ans=ans+que[i].len;}
        }
        printf("%d\n",ans);
    }


    return 0;
}
