#include<string.h>
#include<stdio.h>
int c[999999];
int main()
{
	char str[10];
	int k,n,i,j,a,t;
	scanf("%d",&t);
	getchar();
	while (t--)
	{
		scanf("%d%s",&n,str);
		if (strcmp(str,"FILO")==0)
		{
			j=0;
			for (i=0;i<n;i++)
			{
				scanf("%s",str);
				if (strcmp(str,"IN")==0) 
				{
					scanf("%d",&c[j]);
					j++;
				}
				if (strcmp(str,"OUT")==0) 
				{
					if (j==0) printf("None\n");
					else
					{
						j--;
					printf("%d\n",c[j]);
					}
				}
			}
		}
		else
		{
			i=0;
			j=0;
			for (k=0;k<n;k++)
			{
				scanf("%s",str);
				if (strcmp(str,"IN")==0)
				{
					scanf("%d",&c[j]);
					j++;
				}
				else
				{
					if (i>j-1) printf("None\n");
					else
					{
					printf("%d\n",c[i]);
					i++;
					}
				}
			}
		}
	}
	return 0;
}