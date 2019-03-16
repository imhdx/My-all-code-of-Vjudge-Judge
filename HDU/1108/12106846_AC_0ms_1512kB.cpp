#include<stdio.h>
int main()
{
	int a,b,c,t;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		if (a<b) c=b;
		else
		c=a;
		t=c;
		for (;;c=c+t)
		{
			if (c%a==0&&c%b==0)
			{
				printf("%d\n",c);
				break;
			}
		}
	}
	return 0;
}