#include<stdio.h>
int main()
{
	long long int q,i,s1=0,s2=0,m,n;
	while (scanf("%lld%lld",&n,&m)!=EOF)
	{
		if (n>m) {q=n;n=m;m=q;}
		s1=0;
		s2=0;
	for (i=n;i<=m;i++)
	{
		if (i%2==0) s1=s1+i*i;
		else
		s2=s2+i*i*i;
	}
	printf("%lld %lld\n",s1,s2);
	}
	return 0;
}