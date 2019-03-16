#include<stdio.h>
int main()
{
	int t;
	double q,w;
	char a;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		scanf("%c%lf%lf",&a,&q,&w);
		getchar();
		if (a=='+') printf("%.lf\n",q+w);
		if (a=='-') printf("%.lf\n",q-w);
		if (a=='*') printf("%.lf\n",q*w);
		if (a=='/') printf("%.2lf\n",q/w);
	}
	
	return 0;
}