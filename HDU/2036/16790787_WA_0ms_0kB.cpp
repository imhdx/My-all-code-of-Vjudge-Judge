#include<bits/stdc++.h>
using namespace std;
struct node
{
	double x,y;
}que[120];
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF&&n)
	{
		for (int i=0;i<n;i++)scanf("%lf%lf",&que[i].x,&que[i].y);
		double ans=0;
		for (int i=2;i<n;i++)
		{
			double x1=que[i].x-que[0].x;
			double y1=que[i].y-que[0].y;
			double x2=que[i].x-que[1].x;
			double y2=que[i].y-que[1].y;
			ans+=fabs(x1*y2-x2*y1)/2;
		}
		printf("%.1f\n",ans);
	}
	
	return 0;
}