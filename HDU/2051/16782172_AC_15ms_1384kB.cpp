#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		for (int i=31;i>=0;i--)
		{
			if (n>>i&1)
			{
				for (;i>=0;i--)
				{
					printf("%d",n>>i&1);
				}
			}
		}
		printf("\n");
	}	
	return 0;
}