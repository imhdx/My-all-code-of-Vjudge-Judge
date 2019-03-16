#include<bits/stdc++.h>
using namespace std;
int f(int a,int b,int c)
{
	if (a>b&&a>c&&b>c) return 4*5;
	else if (a>b&&a>c&&b<c) return 4*4;
	else if (b>a&&b>c&&a<c) return 3*4;
	else if (b>a&&b>c&&a>c) return 2*4;
	else if (c>a&&c>b&&a>b) return 4;
	else return 0;
}
int a[10];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		if (n<2)
		{
			printf("0\n");
			continue;
		}
		if (n==2)
		{
			if (a[0]<a[1]) printf("0\n");
			else printf("-1\n");
			continue;
		}
		long long int ans=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j+2<n;j++)
			{
				ans+=f(a[j],a[j+1],a[j+2]);
				sort(a+j,a+j+3);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
