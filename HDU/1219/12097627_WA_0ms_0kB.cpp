#include<stdio.h>
int main()
{
	int i;
	int c[26]={0};
	char a[1000000];
	while (gets(a)!=NULL)
	{
		for (i=0;a[i]!='\0';i++)
		{
			if (a[i]>='a'&&a[i]<='z')
			{
				c[a[i]-'a']++;
			}
		}
		for (i=0;i<26;i++)
		{
			printf("%c:%d\n",'a'+i,c[i]);
		}
		printf("\n");
	}
	return 0;
}