#include<math.h>
#include<stdio.h>
int main()
{
	int i,a;
	while (scanf("%d",&a)!=EOF&&a!=0)
	{
		i=0;
		while (a%2==0)
		{
			i++;
			a=a>>1;
		}
		printf("%d\n",(int)pow(2,i));
	}	
	return 0;
}