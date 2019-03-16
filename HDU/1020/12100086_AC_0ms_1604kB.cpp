#include<stdio.h>
int main()
{
	int i,t,q;
	char a[100000];
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		gets(a);
		q=1;
		for (i=0;a[i]!='\0';i++)
		{
			if (a[i]==a[i+1]) q++;
			else
			{
				if (q==1) printf("%c",a[i]);
				else
				printf("%d%c",q,a[i]);
				q=1;
			}
		}
		printf("\n");
	}
	return 0;
}