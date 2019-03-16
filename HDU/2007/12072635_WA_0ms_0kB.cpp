#include<stdio.h>
int main()
{
	int i,s1=0,s2=0,m,n;
	scanf("%d%d",&n,&m);
	for (i=n;i<=m;i++)
	{
		if (i%2==0) s1=s1+i*i;
		else
		s2=s2+i*i*i;
	}
	printf("%d %d\n",s1,s2);
	return 0;
}