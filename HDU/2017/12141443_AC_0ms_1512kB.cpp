#include<stdio.h>
int main()
{
	char a[9999];
	int tag,t;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		tag=0;
		gets(a);
		for (int i=0;a[i];i++)
		{
			if (a[i]>='0'&&a[i]<='9')  tag++;
		}
		printf("%d\n",tag);
	}
	
	
	
	return 0;
}