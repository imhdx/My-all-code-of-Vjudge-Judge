#include<bits/stdc++.h>
using namespace std;
long long a[55];
int main()
{
	int n;
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	for (int i=4;i<55;i++) a[i]=a[i-1]+a[i-2];
	while (scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",a[n]);
	}
	return 0;
}