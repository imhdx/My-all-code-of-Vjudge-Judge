#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[20];
	while (scanf("%lf",&a[0])!=EOF)
	{
		for (int i=1;i<12;i++)
		scanf("%lf",&a[i]);
		double ans=0;
		for (int i=0;i<12;i++) ans+=a[i];
		ans=ans/12;
		printf("$%.2f\n",ans);
	} 
	return 0;
}