#include<string.h>
#include<stdio.h>
int main()
{
	char a[1000];
	int t,i;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		gets(a);
		for (i=strlen(a)-1;i>=0;i--)
		printf("%c",a[i]);
		printf("\n");
		
	}
	
	
	return 0;
}