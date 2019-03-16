#include<bits/stdc++.h>
using namespace std;
char str[100];
int main()
{
	int n;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",str);
		if (strlen(str)>=8&&strlen(str)<=16)
		{
			int a=0,b=0,c=0,d=0;
			for (int i=0;str[i];i++)
			{
				if (str[i]>='a'&&str[i]<='z') a=1;
				else if (str[i]>='A'&&str[i]<='Z') b=1;
				else if (str[i]>='0'&&str[i]<='9') c=1;
				else d=1;
			}
			if (a+b+c+d>=3) printf("YES\n");
			else
			printf("NO\n");
		}
		else
		printf("NO\n");
	}
	return 0;
}