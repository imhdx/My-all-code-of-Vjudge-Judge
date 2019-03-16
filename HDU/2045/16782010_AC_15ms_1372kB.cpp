#include<bits/stdc++.h>
using namespace std;
long long a[53];
int main()
{
	a[1]=0;
	a[2]=6;
	a[3]=6;	
	for (int i=4;i<53;i++)
	{
		a[i]=a[i-1]+a[i-2]*2;
	}
	a[1]=3;
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",a[n]);
	}
	return 0;
}