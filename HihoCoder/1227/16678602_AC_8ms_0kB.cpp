#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
double a[105];
double b[105];
double k[105][105];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++)
		{
			scanf("%lf%lf",&a[i],&b[i]);
		}
		if (n<m)
		{
			printf("-1\n");
			continue;
		}
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				k[i][j]=sqrt((b[i]-b[j])*(b[i]-b[j])+(a[i]-a[j])*(a[i]-a[j]));
			}
		}
		int i;
		int minn=INF;
		for (i=0;i<n;i++)
		{
			sort(k[i],k[i]+n);
			if (n==m)
				minn=min(minn,(int)k[i][n-1]+1);
			else if ((int)k[i][m-1]+1<k[i][m])
				minn=min(minn,(int)k[i][m-1]+1);
		}
		if (minn>=INF) printf("-1\n");
		else
		printf("%d\n",minn);
	}
	return 0;
}
