#include<stdio.h>
int main()
{
	int a[20003],b[20003];
	int i,j,k,n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		k=n;
		for (i=0;i<n;i++)
		scanf("%d",&a[i]);
		for (i=0;i<m;i++)
		scanf("%d",&b[i]);
		for (i=0;i<m;i++)
		{for (j=0;j<n;j++)
			{
				if (b[i]==a[j]) break;
			}
			if (j==n) {a[k]=b[i];k++;}
		}
		for (i=0;i<k;i++)
		{
			for (j=0;j+1<k-i;j++)
			{
				if (a[j]>a[j+1]) {n=a[j];a[j]=a[j+1];a[j+1]=n;}
			}
		}
		printf("%d",a[0]);
		for (i=1;i<k;i++)
		printf(" %d",a[i]);
		printf("\n");
	}
	
	return 0;
}