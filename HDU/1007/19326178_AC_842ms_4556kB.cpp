#include<bits/stdc++.h>
using namespace std;
struct P
{
    double x,y;
}p[100005],tmp[100005];
double dis(P a,P b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool cmp(P q,P p)
{
    if (q.x==p.x) return q.y<p.y;
    return q.x<p.x;
}
bool cmp1(P q,P p)
{
    return q.y<p.y;
}
double solve(int l,int r)
{
    if (l==r) return 1e9;
    else if (r==l+1) return dis(p[l],p[r]);
    int mid=l+r>>1;
    double maxl=solve(l,mid),maxr=solve(mid+1,r);
    double minn=min(maxl,maxr);
    int t=0;
    for (int i=l;i<=r;i++){
        if (p[i].x>=p[mid].x-minn&&p[i].x<=p[mid].x+minn)
            tmp[t++]=p[i];
    }
    sort(tmp,tmp+t,cmp1);
    for (int i=0;i<t;i++)
    {
        for (int j=i+1;j<t&&tmp[j].y-tmp[i].y<=minn;j++)
            minn=min(minn,dis(tmp[i],tmp[j]));
    }
    return minn;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF&&n)
    {
        for (int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        printf("%.2f\n",solve(0,n-1)/2.0);
    }
    return 0;
}
