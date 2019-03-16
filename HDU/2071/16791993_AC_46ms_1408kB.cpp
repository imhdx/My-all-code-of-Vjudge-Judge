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
		double x;
		scanf("%lf",&x);
		double ans=x;
		for (int i=1;i<n;i++)
		{
			scanf("%lf",&x); ans=max(ans,x);
		}
		printf("%.2f\n",ans);
	}
	return 0;
}