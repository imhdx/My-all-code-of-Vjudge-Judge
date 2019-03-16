#include<stdio.h>
int main()
{
	int a;
	while (scanf("%d",&a)!=EOF)
	{
		if (a%8==2||a%8==6) printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
