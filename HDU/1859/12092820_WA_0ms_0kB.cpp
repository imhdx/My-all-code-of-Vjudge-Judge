#include<stdio.h>
int main()
{
	int xmax,xmin,ymax,ymin;
	int a,b;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		if (a==0&&b==0) break;
		xmin=xmax=a;
		ymin=ymax=b;
		while (scanf("%d%d",&a,&b)!=EOF&&a!=0&&b!=0)		
		{
			if (a>xmax) xmax=a;
			if (a<xmin) xmin=a;
			if (b>ymax) ymax=b;
			if (b<ymin) ymin=b;
		}
		printf("%d %d %d %d\n",xmin,ymin,xmax,ymax);
		
	}
	return 0;
}