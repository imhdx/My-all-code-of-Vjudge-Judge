#include<stdio.h>
int main()
{
	int k,i,j;
	char c;
	int n;
	while (scanf("%c%d",&c,&n)!=EOF)
	{
		getchar();
		if (c=='@') break;
		for (i=1;i<=n;i++)
		{
			k=n-i;
			while (k--) printf(" ");
			if (i==1)
			printf("%c\n",c);
			else if (i==n)
			{
				k=2*n-1;
				while (k--) printf("%c",c);
				printf("\n");
			}
			else
			{
				printf("%c",c);
				k=2*(i-1)-1;
				while (k--) printf(" ");
				printf("%c\n",c);
			}
		}
		printf("\n");
	}
	return 0;
}