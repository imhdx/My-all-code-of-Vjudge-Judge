#include<stdio.h>
int main()
{
	int n,m,s;
	int a[150];
	int i;
	for (i=0;i<150;i++)
	a[i]=2*(i+1);
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		for (i=0;i<n;i=i+m)
		{
			if (i+m-1<n)
			s=(a[i]+a[i+m-1])/2;
			else
			{s=(a[i]+a[n-1])/2;}
			if (i==0)
			printf("%d",s);
			else
			printf(" %d",s);
		}
		printf("\n");
	}
	return 0;
}