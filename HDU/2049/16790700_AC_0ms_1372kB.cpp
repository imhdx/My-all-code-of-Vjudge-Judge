#include<bits/stdc++.h>
using namespace std;
long long a[22];
long long jie[22][22];
int main()
{
	a[1]=0;
	a[2]=1;
	for (int i=3;i<22;i++) a[i]=(a[i-1]+a[i-2])*(i-1);
	jie[1][0]=1;
	jie[1][1]=1;
	for (int i=2;i<22;i++)
	{
		jie[i][0]=1;
		for (int j=1;j<=i;j++) jie[i][j]=jie[i-1][j]+jie[i-1][j-1];
	}
	int m;
	int n;
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		long long ans=a[m]*jie[n][m];
		printf("%lld\n",ans);
	}
	return 0;
}