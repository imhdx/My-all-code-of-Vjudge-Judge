#include<stdio.h>
int main()
{
	char a[99];
	int t;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		gets(a);
		printf("%c",'6');
		puts(a+6);
		
	}
	return 0;
}