#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
double y;
double g(double i)
{
	double ans=(6*i*i*i*i*i*i*i+8*i*i*i*i*i*i+7*i*i*i+5*i*i-y*i);
	return ans;
}
double f(double i)
{
	double ans=42*i*i*i*i*i*i+48*i*i*i*i*i+21*i*i+10*i-y;
	return ans;
}
const double eps=1e-8;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lf",&y);
		double st=0.0;
		double la=100.0;
		double mid=(st+la)/2.0;
		while (fabs(st-la)>eps)
		{
			mid=(st+la)/2.0;
			if (f(mid)<0)
			{
				st=mid;
			}
			else la=mid;
		}
		mid=(st+la)/2;
		double ans=g(mid);
		printf("%.4f\n",ans);
	}
	return 0;
}