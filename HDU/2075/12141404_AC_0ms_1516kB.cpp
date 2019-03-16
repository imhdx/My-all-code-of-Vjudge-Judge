#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if (a%b==0) printf("YES\n");
		else
		printf("NO\n");
	}
	
	
	
	return 0;
	
	
	
}