#include<bits/stdc++.h>
using namespace std;
long long a[22];
long long jie[22];
int main()
{
	jie[0]=1;
	for (int i=1;i<22;i++) jie[i]=jie[i-1]*i;
	a[1]=0;
	a[2]=1;
	for (int i=3;i<22;i++) a[i]=(i-1)*a[i-1]+(i-1)*a[i-2];
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		double ans=(double)a[n]/jie[n]*100;
		printf("%.2f%%\n",ans);
	}	
	return 0;
}