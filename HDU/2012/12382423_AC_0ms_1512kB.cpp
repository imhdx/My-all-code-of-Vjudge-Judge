#include<stdio.h>
#include<math.h>
int prime(int a)
{
	int i;
	if (a<2) return 0;
	for (i=2;i<=(int)sqrt(a);i++)
	{
		if (a%i==0) return 0;
	}
	return 1;
}
int main()
{
	int x,y;
	int i,j;
	int flag=0;
	long long int num[99];
	for (i=-39;i<=50;i++)
		num[i+39]=prime(i*i+i+41);
	while (scanf("%d%d",&x,&y)!=EOF)
	{
		flag=0;
		if (x==0&&y==0) break;
		for (i=x;i<=y;i++)
		{
			if (num[i+39]==0) flag=1;
		}
		if (flag==0) printf("OK\n");
		else
		printf("Sorry\n");
	}
	return 0;
}