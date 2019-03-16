#include<stdio.h>
int main()
{
	int i,flag=0;
	char a[10000];
	while (gets(a)!=NULL)
	{
		for (i=0;a[i]!=0;i++)
		{
			if (a[i]=='"'&&flag==0) {printf("``");flag=1;}
			else if (a[i]=='"'&&flag==1) {printf("''");flag=0;}
			else
			printf("%c",a[i]);
		}
		printf("\n");
	}
	
	return 0;
}