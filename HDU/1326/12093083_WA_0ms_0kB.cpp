#include<math.h>
#include<stdio.h>
int main()
{
	int a[100000];
	int m,k,s,i,n;
	while (scanf("%d",&n)!=EOF&&n!=0)
	{
		m=1;
		k=0;
		s=0;
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s=s+a[i];
		}
		s=s/n;
		for (i=0;i<n;i++)
		{
			k=k+abs(a[i]-s);
		}
//		m++;
		printf("Set #%d\n",m);
		printf("The minimum number of moves is %d.\n\n",k/2);
		m++;
	}	
	return 0;
}