#include<bits/stdc++.h>
using namespace std;
long long poww(long long a,long long b)
{
	long long res=1;
	while (b)
	{
		if (b&1) res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		printf("%lld\n",poww(3,n)-1);
	}
}