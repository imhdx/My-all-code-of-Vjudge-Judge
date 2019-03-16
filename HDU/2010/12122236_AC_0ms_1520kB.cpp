#include<stdio.h>
int main()
{
	int k,t[2000],i,a,b;
	for (i=100;i<=999;i++)
	{
		k=(i%10)*(i%10)*(i%10)+(i/10%10)*(i/10%10)*(i/10%10)+(i/100)*(i/100)*(i/100);
		if (k==i) t[i]=1;
		else
		t[i]=0;
	}
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		k=0;
		for (i=a;i<=b;i++)
		{
			if (t[i]==1) {k++;break;}
		}
		if (k==0) printf("no\n");
		else
		{
			printf("%d",i);
			for (i=i+1;i<=b;i++)
			{
				if (t[i]==1) printf(" %d",i);
			}
			printf("\n");
		}
	}
	return 0;
}