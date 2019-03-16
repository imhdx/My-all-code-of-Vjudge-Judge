#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		double a,b,c;
		scanf("%lf%lf%lf",&a,&b,&c);
		if (a>0&&b>0&&c>0&&a+b>c&&b+c>a&&a+c>b)
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}