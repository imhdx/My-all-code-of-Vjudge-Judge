#include<string.h>
#include<stdio.h>
int main()
{
	int s=0,n,i;
	char a[100000];
	gets(a);
	n=strlen(a);
	for (i=n-1;i>=0;i--)
	{
		if (a[i]=='0') s++;
		if (s==6) break;
	}
	if (i>=0)
	{
		for (;i>=0;i--)
		{
			if (a[i]=='1')
			{printf("yes\n");break;}
		}
		if (i==-1) printf("no\n");
	}
	else
	printf("no\n");
	return 0;
}