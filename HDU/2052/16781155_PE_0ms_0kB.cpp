#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		swap(n,m);
		n=n+2;
		m=m+2;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (i==0&&j==0||i==0&&j==m-1||i==n-1&&j==0||i==n-1&&j==m-1)
				printf("+");
				else if (i==0||i==n-1) printf("-");
				else if (j==0||j==m-1) printf("|");
				else
				printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}