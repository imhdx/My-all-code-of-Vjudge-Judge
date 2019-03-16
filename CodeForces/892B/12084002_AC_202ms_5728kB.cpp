#include<stdio.h>
int main()
{
	int i,min,a,n,b[1000006];
	while (~scanf("%d",&n))
	{
		a=1;
		for (i=1;i<=n;i++)
		scanf("%d",&b[i]);
		min=n-b[n];
		for (i=n;i>=1;i--)
		{
			if (i<min) a++;
			if (min>i-b[i]) min=i-b[i];
		}
		printf("%d\n",a);
	}
	
	return 0;
}