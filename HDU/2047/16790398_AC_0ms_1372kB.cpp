#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a[42];//ojiewei
	long long int b[42];
	a[1]=1;
	b[1]=2;
	for (int i=2;i<40;i++)
	{
		a[i]=b[i-1];
		b[i]=a[i-1]*2+b[i-1]*2;
	}
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",a[n]+b[n]);
	}
}