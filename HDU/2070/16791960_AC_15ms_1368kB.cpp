#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a[52];
	a[0]=0;
	a[1]=1;
	for (int i=2;i<52;i++) a[i]=a[i-1]+a[i-2];
	int n;
	while (scanf("%d",&n)!=EOF&&n!=-1)
	{
		printf("%lld\n",a[n]);
	}
	return 0;
}