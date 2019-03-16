#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char ch=getchar();while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
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
    n=read();
    k=read();
    for (int i=1;i<=n;i++)
        p[i].x=read(),p[i].y=read(),p[i].z=read();
    sort(p+1,p+1+n,cmp1);
    int tot=0;
    int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cnt++;
		if(p[i].x!=p[i+1].x||p[i].y!=p[i+1].y||p[i].z!=p[i+1].z)
		{
			p[++tot]=p[i];
			p[tot].cnt=cnt;
			cnt=0;
		}
	}
    if (tot!=1) cdq(1,tot);
    for (int i=1;i<=tot;i++) ans[p[i].sum+p[i].cnt-1]+=p[i].cnt;
    for (int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
