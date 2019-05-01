#include<bits/stdc++.h>
using namespace std;
const double pi=4*atan(1.0);
mt19937 rng((unsigned long long)new char);
double myrng()
{
    return 1.0*rng()/2.0/INT_MAX;
}
struct P
{
    double x,y;
}p[100005];
bool cmp(P q,P p)
{
    if (q.x==p.x) return q.y<p.y;
    return q.x<p.x;
}
P rotate(P a,double t)
{
    return P{a.x*cos(t)-a.y*sin(t),a.y*cos(t)+a.x*sin(t)};
}
double dis(int i,int j)
{
    return sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
}
double solve(int a,int b)
{

    double minn=1e9;
    for (int i=a;i<b;i++)
    {
        for (int j=i+1;j<b;j++)
        {
            minn=min(minn,dis(i,j));
        }
    }
    return minn;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n==0) return 0;
        for (int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        double minn=1e9;
        double t=myrng()*2*pi;
        for (int i=0;i<n;i++) p[i]=rotate(p[i],t);
        sort(p,p+n,cmp);
        int block=sqrt(n)+10;
        for (int i=0;i<n;i+=block)
        {
            minn=min(minn,solve(i,min(i+block,n)));
        }
        printf("%.2f\n",minn/2.0);
    }
    return 0;
}
