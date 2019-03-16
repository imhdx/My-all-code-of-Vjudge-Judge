#include<stdio.h>
int main()
{
	int i,j;
	char b[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./",a[10000];
	while (gets(a)!=NULL)
	{
		for (i=0;a[i]!=0;i++)
		{
			if (a[i]==' ') printf(" ");
			else
			{
				for (j=0;b[j]!=a[i];j++);
				printf("%c",b[j-1]); 
			}
		}
		printf("\n");
	}
	
	
	return 0;
}