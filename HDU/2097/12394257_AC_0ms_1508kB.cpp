#include<stdio.h>
int main()
{
	int a,b,c,s,n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==0) break;
	s=n;
			a=s%10+s/10%10+s/100%10+s/1000;
	b=s%16+s/16%16+s/(16*16)%16+s/(16*16*16)%16;
	c=s%12+s/12%12+s/(12*12)%12+s/(12*12*12)%12;	
	if (a==b&&b==c) printf("%d is a Sky Number.\n",n);
	else
	printf("%d is not a Sky Number.\n",n);
		
		
	}
	return 0;
}