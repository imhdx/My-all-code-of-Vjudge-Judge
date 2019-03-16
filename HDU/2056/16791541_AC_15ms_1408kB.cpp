#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x1,x2,y1,y2,x3,x4,y3,y4;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
	{
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
		if (x3>x4) swap(x3,x4);
		if (y3>y4) swap(y3,y4);
		//printf("%f %f \n%f %f\n %f %f\n %f %f\n",x1,y1,x2,y2,x3,y3,x4,y4);
		double l=min(x2,x4)-max(x1,x3);
		double a=min(y2,y4)-max(y1,y3);
		//printf("l=%f a=%f\n",l,a);
		if (l<=0||a<=0) printf("0.00\n");
		else
		printf("%.2f\n",l*a); 
	}
	return 0;
}