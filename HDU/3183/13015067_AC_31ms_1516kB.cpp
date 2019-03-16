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
				i=i-2;
				if (k==m) break;
			}
		}
		if (k==m)
		{
			for (i=0;a[i];i++)
			if (a[i]!='0') break;
			if (a[i]==0) printf("0\n");
			else
			{
			for (;a[i];i++)
			printf("%c",a[i]);
			printf("\n");
			}
		}
		else
		{
			len=len-(m-k);
			if (len<=0) printf("0\n");
			else
			{
				for (i=0;i<len;i++)
					if (a[i]!='0') break;
				if (a[i]==0) printf("0\n");
				else
				{
					for (;i<len;i++)
						printf("%c",a[i]);
					printf("\n");
				}
			}
		}
	}
	return 0;
}