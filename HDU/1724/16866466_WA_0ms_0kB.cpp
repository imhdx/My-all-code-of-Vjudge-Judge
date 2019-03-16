#include<bits/stdc++.h>
using namespace std;
typedef double lf;
const lf EPS=1e-6;
lf simpson(lf a,lf b,lf f(lf x))
{
    return (f(a)+2*f((a+b)/2)+f(b))*(b-a)/2;
}
lf ask(lf a,lf b,lf f(lf x),lf e=EPS)
{
    lf c=(a+b)/2,L=simpson(a,c,f),R=simpson(c,b,f),A=simpson(a,b,f);
    return fabs(L+R-A)<EPS*15?L+R+(L+R-A)/15:ask(a,c,f,e/2)+ask(c,b,f,e/2);
}
lf a,b,x,y;
lf f(lf x){return sqrt(b*b-b*b*x*x/a/a);}///返回x=x0直线与图像相交的线段长度(可以用对称性减小常数
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
        printf("%.3f\n",ask(x,y,f));///对称
    }
    return 0;
}
