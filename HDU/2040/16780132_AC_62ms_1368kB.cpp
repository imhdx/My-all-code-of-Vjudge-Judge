#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		int tmp=0;
		for (int i=1;i<n;i++)
		{
			if (n%i==0)
			{
				tmp+=i;
				if (tmp>m) break;
			}
		}
		if (tmp==m)
		{
			printf("YES\n");
			continue;
		}
		tmp=0;
		for (int i=1;i<m;i++)
		{
			if (m%i==0)
			{
				tmp+=i;
				if (tmp>n) break;
			}
		}
		if (tmp==n)
		{
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}