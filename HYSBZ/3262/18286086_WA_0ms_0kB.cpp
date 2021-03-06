#include<bits/stdc++.h>
using namespace std;
struct ac
{
    int t[200005];
    void add(int i,int x)
    {
        while (i<200005)
        {
            t[i]+=x;
            i+=i&(-i);
        }
    }
    int sum(int i)
    {
        int ans=0;
        while (i>0)
        {
            ans+=t[i];
            i-=i&(-i);
        }
        return ans;
    }
}bit;
struct node
{
    int x,y,z;
    int cnt;
    int sum;
}p[100005];
bool cmp1(node q,node p)
{
    if (q.x==p.x)
    {
        if (q.y==p.y) return q.z<p.z;
        else return q.y<p.y;
    }
    else return q.x<p.x;
}
bool cmp2(node q,node p)
{
    if (q.y==p.y) return q.z<p.z;
    return q.y<p.y;
}
void cdq(int l,int r)
{
    if (l==r) return ;
    int m=l+r>>1;
    cdq(l,m);
    cdq(m+1,r);
    sort(p+l,p+m+1,cmp2);
    sort(p+m+1,p+r+1,cmp2);
    int j=l;
    for (int i=m+1;i<=r;i++)
    {
        for (;j<=m&&p[j].y<=p[i].y;j++) bit.add(p[j].z,p[j].cnt);
        p[i].sum+=bit.sum(p[i].z);
    }
    for (int i=l;i<j;i++) bit.add(p[i].z,-p[i].cnt);

}
int ans[100005];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++)
        scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
    sort(p+1,p+1+n,cmp1);
    int tot=1;
    int j;
    for (int i=1;i<=n;i=j)
    {
        for (j=i;j<=n&&p[i].x==p[j].x&&p[i].y==p[j].y&&p[i].z==p[j].z;j++);
        p[i].cnt=j-i;
        p[tot++]=p[i];
    }
    cdq(1,tot-1);
    for (int i=1;i<tot;i++) ans[p[i].sum]++;
    for (int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
