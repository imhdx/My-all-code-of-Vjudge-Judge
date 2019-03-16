#include<bits/stdc++.h>
using namespace std;
int a[120];
int b[120];
char str[111];
int main()
{
	int test=0;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		if (test) printf("\n");
		test=1;
		int n;
		scanf("%d",&n);
		bool flag=0;
		for (int i=0;i<n;i++)
		{
			scanf("%s%d%d",str,&a[i],&b[i]);
			if (b[i]>=0&&b[i]<60) flag=1;
		}
		long long sum1=0;
			long long sum2=0;
			for (int i=0;i<n;i++)
			{
				sum1+=a[i]*b[i];
				sum2+=a[i];
			}
			double ans=(double)sum1/sum2;
			if (flag==1) printf("Sorry!\n");
			else
			printf("%.2f\n",ans);
	}
	return 0;
}