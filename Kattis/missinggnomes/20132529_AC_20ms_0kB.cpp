#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
bool vis[100005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
		vis[a[i]]=1;
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		if (vis[i]==0)
		b[cnt++]=i;
	}
	int i=0,j=0;
	while (i<m&&j<cnt)
	{
		if (a[i]<b[j])
		{
			printf("%d\n",a[i]);
			i++;
		}
		else {
			printf("%d\n",b[j]);
			j++;
		}
	}
	while (i<m)
	{
		printf("%d\n",a[i]);
		i++;
	}
	while (j<cnt)
	{
		printf("%d\n",b[j]);
		j++;
	}
	return 0;
}