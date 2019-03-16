#include<bits/stdc++.h>
using namespace std;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0,f=1;
    while(!(ch>='0'&&ch<='9'))
    {if (ch=='-') f=-1;ch=nc();}
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum*f;
}
int n;
struct ac
{
    int x,y;
}que[200005];
bool cmp1(const ac &q,const ac &p)
{
    if (q.x==p.x) return q.y<p.y;
    return q.x<p.x;
}
bool cmp2(const ac &q,const ac &p)
{
    if (q.y==p.y) return q.x<p.x;
    return q.y<p.y;
}

struct node
{
    int k,x1,x2,y;   ///k=0 x1,x2为横坐标，y为纵坐标
                     ///k=1  表示竖线的上端点
                     ///k=-1 表示竖线的下端点
}qqq[1000005];
int cnt=0;
vector<int> v;
int find(int x){return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
void insert(int k,int x,int y,int z)
{
    if (k==0)///插入横线  x为左端点横坐标  y为右端点横坐标  z为纵坐标
    {
        qqq[cnt++]=node{0,find(x),find(y),z};
    }
    else///插入竖线 x为横坐标  y为下端点的纵坐标 z为上端点的纵坐标
    {
        qqq[cnt++]=node{1,find(x),0,z};
        qqq[cnt++]=node{-1,find(x),0,y};
    }
}
bool cmp3(const node &q,const node &p)
{
    if (q.y==p.y) return q.k<p.k;
    return q.y<p.y;
}

long long t[200005];
void add(int i,int s)
{
    while (i<200005)
    {
        t[i]+=s;
        i+=i&-i;
    }
}
int ask(int i)
{
    int ans=0;
    while (i)
    {
        ans+=t[i];
        i-=i&-i;
    }
    return ans;
}
int ask(int l,int r)
{
    return ask(r)-ask(l-1);
}

int main()
{
    int n=read();
    for (int i=0;i<n;i++)
    {
        que[i].x=read();
        que[i].y=read();
        v.push_back(que[i].x);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    sort(que,que+n,cmp1);
    int i,j;
    for (i=0;i<n;i=j)
    {
        j=i;
        while (j<n&&que[i].x==que[j].x) j++;
        insert(1,que[i].x,que[i].y,que[j-1].y);///插入竖线
    }
    sort(que,que+n,cmp2);
    for (i=0;i<n;i=j)
    {
        j=i;
        while (j<n&&que[i].y==que[j].y) j++;
        insert(0,que[i].x,que[j-1].x,que[i].y);///插入横线
    }
    sort(qqq,qqq+cnt,cmp3);
    long long ans=0;
    for (int i=0;i<cnt;i++)
    {
        if (qqq[i].k==0)
        {
            ans+=ask(qqq[i].x1,qqq[i].x2);
            //printf("%lld\n",ans);
        }
        else add(qqq[i].x1,qqq[i].k);
    }
    printf("%lld\n",abs(ans));
    return 0;
}
