#include<stdio.h>
int main()
{
	int k,i,j;
	char c;
	int n;
	int flag=0;
	while (scanf("%c%d",&c,&n)!=EOF)
	{
		getchar();
		if (c=='@') break;
		if (flag==1) printf("\n");
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
			flag=1;
		}
	}
	return 0;
}