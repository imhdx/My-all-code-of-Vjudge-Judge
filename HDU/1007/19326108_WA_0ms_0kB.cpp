#include<bits/stdc++.h>
using namespace std;
struct P
{
    double x,y;
}p[100005],tmp[100005];
double dis(int i,int j)
{
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
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
    else if (r==l+1) return dis(l,r);
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
        for (int j=i+1;j<t&&p[j].y-p[i].y<=minn;j++)
            minn=min(minn,dis(i,j));
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
