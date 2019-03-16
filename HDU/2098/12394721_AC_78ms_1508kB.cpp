#include<math.h>
#include<stdio.h>
int prime(int a)
{
	if (a<2) return 0;
	for (int i=2;i<=(int)sqrt(a);i++)
	{
		if (a%i==0) return 0;
	}
	return 1;
}
int main()
{
	int k,i,n;
	while (scanf("%d",&n)!=EOF)
	{
		k=0;
		if (n==0) break;
		for (i=1;i<(n-i);i++)
		{
			if (prime(i)==1&&prime(n-i)==1)
			k++;
		}
		printf("%d\n",k);
	}
	return 0;
}