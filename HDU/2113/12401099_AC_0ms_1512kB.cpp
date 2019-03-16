#include<stdio.h>
int main()
{
	int s=0;
	int n;
	int flag=0;
	while (scanf("%d",&n)!=EOF)
	{
		s=0;
		if (flag==1) printf("\n");
		while (n!=0)
		{
			if (n%2==0) s=s+n%10;
			n=n/10;
		}
		printf("%d\n",s);
		flag=1;
	}
	return 0;
}