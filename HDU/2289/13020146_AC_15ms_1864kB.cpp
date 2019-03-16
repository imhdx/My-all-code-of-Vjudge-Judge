#include<stdio.h>
#include<math.h>
#define PI (atan(1.0)*4.0)
double r,R,H,V;
double f(double h)
{
	double rr=h/H*(R-r)+r;
	return 1/3.0*h*PI*(r*r+rr*rr+r*rr);
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lf%lf%lf%lf",&r,&R,&H,&V);
		double qq=0.0,pp=H;
		double mid;
		while (pp-qq>(1e-8))
		{
			mid=(qq+pp)/2.0;
			if (f(mid)<V) qq=mid;
			else if(f(mid)>V) pp=mid;
		}
		printf("%.6f\n",mid);
	}
	return 0;
}