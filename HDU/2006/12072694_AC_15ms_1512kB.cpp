#include<stdio.h>
int main()
{
	int s,i,a,n;
	while (scanf("%d",&n)!=EOF)
	{
		s=1;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&a);
			if (a%2!=0)
		s=s*a;
		}
		printf("%d\n",s);
	}
	return 0;

}