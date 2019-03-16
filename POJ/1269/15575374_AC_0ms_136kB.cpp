#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
const int mod=1e9+7;
const double PI=3.141592653598793;
typedef long long ll;
ll poww(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
            res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
const double eps=1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)
        return 0;
    if (x<0)
        return -1;
    else
        return 1;
}



struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x=_x;
        y=_y;
    }
     double operator ^(const Point &b)const{return x*b.y - y*b.x;}
     Point operator -(const Point &b)const{return Point(x-b.x,y-b.y);}
};
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s=_s;
        e=_e;
    }
    int relation(Point p)
    {
        int c=sgn((p-s)^(e-s));
        if(c < 0)
            return 1;
        else if(c > 0)
            return 2;
        else
            return 3;
    }
    bool parallel(Line v)
    {
        return sgn((e-s)^(v.e-v.s))==0;
    }
    int linecrossline(Line v)
    {
        if((*this).parallel(v))
            return v.relation(s)==3;
        return 2;
    }
    Point crosspoint(Line v)
    {
        double a1=(v.e-v.s)^(s-v.s);

        double a2=(v.e-v.s)^(e-v.s);

        return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
    }
};
//两直线关系
//0 平行
//1 重合
//2 相交

//求两直线的交点
//要保证两直线不平行或重合
int main()
{
    int n;
    double x1,x2,y1,y2,x3,y3,x4,y4;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    while (n--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        Point a1(x1,y1),a2(x2,y2),a3(x3,y3),a4(x4,y4);
        Line k1(a1,a2),k2(a3,a4);
        if (k1.linecrossline(k2)==0)
            printf("NONE\n");
        else if (k1.linecrossline(k2)==1)
        {
            printf("LINE\n");
        }
        else
        {
            Point tt=k1.crosspoint(k2);
            printf("POINT %.2f %.2f\n",tt.x,tt.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
