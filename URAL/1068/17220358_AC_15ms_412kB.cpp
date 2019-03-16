#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if (n==1) printf("1\n");
		else if (n>1)
		{
			int ans=(1+n)*n/2;
			printf("%d\n",ans);
		}
		else
		{
			int ans=(1+n)*(1-n+1)/2;
			printf("%d\n",ans);
		}
	}
	
	return 0;
}