#include<stdio.h>
int main()
{
	int n;
	int a[999];
	int min,i,t;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0) break;
		scanf("%d",&a[0]);
		t=0;
		for (i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if (a[t]>a[i]) t=i;
		}
		min=a[0];
		a[0]=a[t];
		a[t]=min;
		printf("%d",a[0]);
		for (i=1;i<n;i++)
		printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}