#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100010;
const int INF=0x3f3f3f3f;
struct Point
{
    int x,y,id;
}p[MAXN];
bool cmp(Point a,Point b)
{
    if (a.x!=b.x) return a.x<b.x;
    return a.y<b.y;
}
struct BIT
{
    int min_val,pos;
    void init()
    {
        min_val=INF;
        pos=-1;
    }
}bit[MAXN];
struct Edge
{
    int x,y,w;
}edge[MAXN<<2];
bool cmpedge(Edge a,Edge b)
{
    return a.w<b.w;
}
int tot;
int n;
int pre[MAXN];
int getx(int x)
{
    if (pre[x]==-1) return x;
    return pre[x]=getx(pre[x]);
}
void addedge(int u,int v,int d)
{
    edge[tot++]=Edge{u,v,d};
}
int lowbit(int x)
{
    return x&(-x);
}
void updata(int i,int val,int pos)
{
    while (i>0)
    {
        if (val<bit[i].min_val)
        {
            bit[i].min_val=val;
            bit[i].pos=pos;
        }
        i-=lowbit(i);
    }
}
int ask(int i,int m)
{
    int min_val=INF,pos=-1;
    while (i<=m)
    {
        if (bit[i].min_val<min_val)
        {
            min_val=bit[i].min_val;
            pos=bit[i].pos;
        }
        i+=lowbit(i);
    }
    return pos;
}
int dist(Point a,Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
void solve(int n,Point p[])
{
    int a[MAXN],b[MAXN];
    tot=0;
    for (int j=0;j<4;j++)
    {
        if (j==1||j==3)
            for (int i=0;i<n;i++) swap(p[i].x,p[i].y);
        else if (j==2)
            for (int i=0;i<n;i++) p[i].x*=-1;
        sort(p,p+n,cmp);
        for (int i=0;i<n;i++)
            a[i]=b[i]=p[i].y-p[i].x;
        sort(b,b+n);
        int m=unique(b,b+n)-b;
        for (int i=1;i<=m;i++) bit[i].init();
        for (int i=n-1;i>=0;i--)
        {
            int pos=lower_bound(b,b+m,a[i])-b+1;
            int ans=ask(pos,m);
            if (ans!=-1) addedge(p[i].id,p[ans].id,dist(p[i],p[ans]));
            updata(pos,p[i].x+p[i].y,i);
        }
    }
}
int solve(int k)
{
    solve(n,p);
    memset(pre,-1,sizeof(pre));
    sort(edge,edge+tot,cmpedge);
    for (int i=0;i<tot;i++)
    {
        int xx=getx(edge[i].x);
        int yy=getx(edge[i].y);
        if (xx!=yy)
        {
            pre[min(xx,yy)]=max(xx,yy);
            k--;
            if (k==0) return edge[i].w;
        }
    }
}
int main()
{
    int k;
    while (scanf("%d%d",&n,&k)!=EOF)
    {
        for (int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y),p[i].id=i;
        printf("%d\n",solve(n-k));
    }
    return 0;
}
