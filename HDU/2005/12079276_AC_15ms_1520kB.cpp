#include<stdio.h>
int main()
{
	int m,n,t,a[12]={31,28,31,30,31,30,31,31,30,31,30,31},i;
	while(scanf("%d/%d/%d",&m,&n,&t)!=EOF)
	{
		if (m%4==0&&m%100!=0||m%400==0)
			a[1]=29;
		else a[1]=28;
		for(i=0;i<n-1;i++)
			t+=a[i];
		printf("%d\n",t);
	}
	return 0;
}