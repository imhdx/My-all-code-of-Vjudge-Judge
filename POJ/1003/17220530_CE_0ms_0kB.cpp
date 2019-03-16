#include<bits/stdc++.h>
using namespace std;
double a[10000];
int main()
{
	a[2]=0.5;
	int i;
	int cnt;
	for (cnt=3;a[cnt-1]<=5.20;cnt++)
	{
		a[cnt]=a[cnt-1]+1.0/cnt;
	}
	double x;
	while (scanf("%lf",&x)!=EOF)
	{
		if (x==0.00) return 0;
		
		for (int i=2;i<cnt;i++)
		{
			if (a[i]>x)
			{
				printf("%d card(s)\n",i-1);
				break;
			}
		}
	}
	return 0;
}