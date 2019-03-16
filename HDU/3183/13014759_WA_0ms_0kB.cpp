#include<string.h>
#include<stdio.h>
int main()
{
	char a[9999];
	int m;
	while (scanf("%s%d",a,&m)!=EOF)
	{
		int len=strlen(a);
		int i,j,k=0;
		for (i=0;i<len;i++)
		{
			if (a[i]>a[i+1])
			{
				k++;
				for (j=i;j<len;j++)
				a[j]=a[j+1];
				len--;
				if (k==m) break;
			}
		}
		for (i=0;a[i];i++)
		{
			if (a[i]!='0') break;
		}
		if (i==len) {printf("0\n");continue;}
		if (k==m)
		for (;a[i];i++)
		printf("%c",a[i]);
		else
		{
			if (len<=(m-k)) printf("0");
			else
			{
				for (;a[i-(m-k)];i++)
				printf("%c",a[i]);
			}
		}
		printf("\n");
	}
	return 0;
}