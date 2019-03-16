#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n<0||n>100) printf("Score is error!\n");
		else
		{
			switch (n/10)
			{
				case 10:
				case 9: printf("A\n");break;
				case 8:printf("B\n");break;
				case 7:printf("C\n");break;
				case 6:printf("D\n");break;
				default :printf("E\n");
			}
		}
	}
	return 0;
}