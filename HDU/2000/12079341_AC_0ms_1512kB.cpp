#include<stdio.h>
int main()
{
	char n,a,b,c;
	while (scanf("%c%c%c",&a,&b,&c)!=EOF)
	{
		getchar();
		if (a>b){n=a;a=b;b=n;}
		if (b>c){n=b;b=c;c=n;}
		if (a>b){n=a;a=b;b=n;}
		printf("%c %c %c\n",a,b,c);
	}
	return 0;
}