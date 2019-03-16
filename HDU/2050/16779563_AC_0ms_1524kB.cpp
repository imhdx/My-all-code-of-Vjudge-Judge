#include<bits/stdc++.h>
using namespace std;
long long int a[20004];
int main()
{
	int T;
	a[0]=1;
	a[1]=2;
	//printf("%d\n",a[0]);
	//printf("%d\n",a[1]);
	for (int i=2;i<20004;i++)
	{
		a[i]=a[i-1]+4*i-3;
	}
	

	
	scanf("%d",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		printf("%lld\n",a[n]);
	}
	
	return 0;
}