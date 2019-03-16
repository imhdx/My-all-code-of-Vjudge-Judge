/*2016 10 21
*/

#include<stdio.h>
int main()
{
	int s,i,a,b,t,c[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&t);
	while (t--)
	{
		s=0;
		scanf("%d%d",&a,&b);
		if (a==10&&b==21) printf("It's today!!\n");
		else if (a==10&&b>21||a>10)
		printf("What a pity, it has passed!\n");
		else if (a==10)
		printf("%d\n",21-b);
		else
		{
			for (i=a+1;i<10;i++)
			s=s+c[i];
			s=s+c[a]-b+21;
			printf("%d\n",s);
		}
	}
	
	return 0;
}