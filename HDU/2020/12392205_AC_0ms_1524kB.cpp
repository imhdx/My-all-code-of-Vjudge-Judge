#include<math.h>
#include<stdio.h>
int main()
{
	int j,i,a[999];
	int t,n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0) break;
		for (i=0;i<n;i++)
		scanf("%d",&a[i]);
		for (i=1;i<n;i++)
		for (j=0;j<n-i;j++)
		{
			if (abs(a[j])<abs(a[j+1]))
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}		
		}
		printf("%d",a[0]);
		for (i=1;i<n;i++)
		printf(" %d",a[i]);
		printf("\n");
	}
	return 0;
}