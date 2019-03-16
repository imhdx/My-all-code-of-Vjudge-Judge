#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (scanf("%d",&n)!=EOF)
	{
		if ((int)sqrt(n)==sqrt(n))
		printf("1\n");
		else
		printf("0\n");
	}
	return 0;
}