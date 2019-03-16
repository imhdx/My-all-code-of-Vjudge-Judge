#include<string.h>
#include<stdio.h>
char a[99999];
int main()
{
	int len;
	int s;
	while (gets(a)!=NULL)
	{
		s=0;
		for (int i=0;;i++)
		{
			if (a[i]=='B') break;
			if (a[i]=='(') s++;
			if (a[i]==')') s--;
		}
		printf("%d\n",s);
	}
	return 0;
}