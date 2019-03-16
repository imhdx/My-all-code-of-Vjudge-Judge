#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
struct ios{inline char read(){static const int IN_LEN=1<<18|1;static char buf[IN_LEN],*s,*t;return (s==t)&&(t=(s=buf)+fread(buf,1,IN_LEN,stdin)),s==t?-1:*s++;}template<typename _Tp>inline ios &operator>>(_Tp&x){static char c11,boo;for(c11=read(),boo=0;!isdigit(c11);c11=read()){if(c11==-1)return *this;boo|=c11=='-';}for(x=0;isdigit(c11);c11=read())x=x*10+(c11^'0');boo&&(x=-x);return *this;}}io;
int n,k,t[200005],ans[100005];
inline void add(int x,int num)
{
	for(int i=x;i<=k;i+=i&-i)
	    t[i]+=num;
}
inline int sum(int x)
{
	int tmp=0;
	for(int i=x;i;i-=i&-i)
	    tmp+=t[i];
	return tmp;
}
struct node
{
    int x,y,z;
    int cnt;
    int sum;
    bool operator<(const node &p)const
    {
        return y<p.y;
    }
}p[100005];
inline bool cmp1(node q,node p)
{
    if (q.x==p.x)
    {
        if (q.y==p.y) return q.z<p.z;
        else return q.y<p.y;
    }
    else return q.x<p.x;
}
inline void cdq(int l,int r)
{
    int m=(l+r)>>1;
    if (l!=m) cdq(l,m);
    if (m+1!=r) cdq(m+1,r);
    sort(p+l,p+m+1);
    sort(p+m+1,p+r+1);
    int j=l;
    for (int i=m+1;i<=r;i++)
    {
        for (;j<=m&&p[j].y<=p[i].y;j++) add(p[j].z,p[j].cnt);
        p[i].sum+=sum(p[i].z);
    }
    for (int i=l;i<j;i++) add(p[i].z,-p[i].cnt);
}
int main()
{
    io>>n>>k;
    for (int i=1;i<=n;i++)
        io>>p[i].x>>p[i].y>>p[i].z;
    sort(p+1,p+1+n,cmp1);
    int tot=1;
    int j;
    for (int i=1;i<=n;i=j)
    {
        for (j=i;j<=n&&p[i].x==p[j].x&&p[i].y==p[j].y&&p[i].z==p[j].z;j++);
        p[i].cnt=j-i;
        p[tot++]=p[i];
    }
    if (tot!=2) cdq(1,tot-1);
    for (int i=1;i<tot;i++) ans[p[i].sum+p[i].cnt-1]+=p[i].cnt;
    for (int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
