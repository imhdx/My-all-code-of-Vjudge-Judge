#include<stdlib.h>
#include<string.h>
#include<stdio.h>
char b[1000010];
int main()
{
	long long s,n,i,j,a[1000010];
	memset(b,0,1000010*sizeof(char ));
	scanf("%lld",&n);
	for (i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	for (i=n;i>=1;i--)
	{
		if (i-a[i]<=1)
		{memset(&b[1],1,(i-1)*sizeof(char ));break;}
		else
		{
			memset(&b[i-a[i]],1,a[i]*sizeof(char ));
		}
	}
	s=0;
	for (i=1;i<=n;i++)
	if (b[i]==0) s++;
	printf("%lld\n",s);
	return 0;
}