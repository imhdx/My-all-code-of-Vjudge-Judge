#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>

using namespace std;
double esp=1e-3;
int n;
double x[1003];
double y[1003];
//mt19937 rng((unsigned long long)new char);
///这里用mt19937的话，随机性会非常好，整个算法的效率和正确性可以得到很大的提升，就是POJ不能用
double myrand()///生成[0,1]的随机数
{
    //return 1.0*rng()/INT_MAX;
    return 1.0*rand()/RAND_MAX;
}
const double pi=4*atan(1.0);
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int maxx,maxy;
        scanf("%d%d%d",&maxx,&maxy,&n);
        for (int i=0;i<n;i++) scanf("%lf%lf",&x[i],&y[i]);
        double xx=maxx/2.0;
        double yy=maxy/2.0;///取矩形正中央的点为起点，理论上可以随机取。
        double t=2*sqrt(1.0*maxx*maxx+1.0*maxy*maxy);///初始酒劲，保证从初始点可以跳到任意合法位置
        double ans=0;
        while (t>esp)
        {
            double p=myrand();
            double a=2*pi*p;///随机下一点的方向
            double tx=xx+1.5*t*p*p*sin(a);///1.5*t*p*p是下一个点与当前点的距离
                            ///可以发现，t越大1.5*t*p*p越大
                            ///对应兔子酒劲很大，可以随机到的范围很大
            double ty=yy+1.5*t*p*p*cos(a);
            if (tx<0||tx>maxx||ty<0||ty>maxy) continue;///保证(tx,ty)位置合法
            double tmp=1e30;
            for (int i=0;i<n;i++)
            {
                tmp=min(tmp,sqrt((tx-x[i])*(tx-x[i])+(ty-y[i])*(ty-y[i])));
            }///求出下一个点与n的点距离的最小值。
            double sub=tmp-ans;
            if (sub>=0)///是更优解，则更新
            {
                ans=tmp;
                xx=tx;
                yy=ty;
            }
            t*=0.9965;///兔子的酒劲慢慢变小，重点调这个参数
        }
        printf("The safest point is (%.1f, %.1f).\n",xx,yy);
    }
    return 0;
}
