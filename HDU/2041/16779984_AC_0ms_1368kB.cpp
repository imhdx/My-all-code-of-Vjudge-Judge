#include<bits/stdc++.h>
using namespace std;
long long a[50];
int main()
{
	int T;
	a[1]=0;
	a[2]=1;
	a[3]=2;
	for (int i=4;i<50;i++) a[i]=a[i-1]+a[i-2];
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}