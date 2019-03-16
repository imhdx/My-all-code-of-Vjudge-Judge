#include<math.h>
#include<stdio.h>
int main()
{
	int n,m;
	double s,t;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		t=n;
		s=0;
		for (int i=0;i<m;i++)
		{
			s=s+t;
			t=sqrt(t);
		}
		printf("%.2lf\n",s);
	}
	return 0;
}