#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		long long ans=3;
		for (int i=0;i<n;i++)
		{
			ans=(ans-1)*2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}