#include<stdio.h>
int main()
{
	int t,a,b,j,i;
	scanf("%d",&t);
	while (t--)
	{
		j=0;
		scanf("%d%d",&a,&b);
		for (i=a;;i++)
		{
			if (i%4==0&&i%100!=0||i%400==0) j++;
			if (j==b) break;
		}
		printf("%d\n",i);
	}

	return 0;
}