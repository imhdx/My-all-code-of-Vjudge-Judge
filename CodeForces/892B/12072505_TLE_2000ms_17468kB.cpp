#include<stdio.h>
long long b[1000010];
int main()
{
	long long s,n,i,j,a[1000010];
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for (i=n;i>=1;i--)
	{
		for (j=i-1;j>=1;j--,a[i]--)
		{
			if (a[i]==0) break;
			b[j]=1;
		}
	}
	s=0;
	for (i=1;i<=n;i++)
	if (b[i]!=1) s++;
	printf("%lld\n",s);
	return 0;
}