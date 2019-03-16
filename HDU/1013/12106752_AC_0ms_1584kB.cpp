#include<stdio.h>
int f(long long a)
{
	if (a/10==0) return a;
	long long c=0;
	while (a!=0)
	{
		c=c+a%10;
		a=a/10;
	}
	return f(c);
}
int main()
{
	char q[99999];
	int i;
	long long int a;
	while (gets(q)!=NULL)
	{
		a=0;
		if (q[0]=='0'&&q[1]=='\0') break;
		for (i=0;q[i]!=0;i++)
		{
			a=a+q[i]-'0';
		}
		printf("%d\n",f(a));
	}
	return 0;
}