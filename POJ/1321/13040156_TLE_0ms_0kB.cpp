#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
char a[10][10];
int ans=0;
int book[10];
void dfs(int step,int hang)
{
	int i,j;
	if (step>k)
		return ;
	if (hang>=n) return ;
	for (i=0;i<n;i++)
	{
		if (a[hang][i]=='#')
		{
			for (j=0;j<hang;j++)
			{
				if (book[hang]==i)
				break;
			}
			if (j<hang)
			{
				if (hang<n-1) 
				dfs(step,hang+1);
			}
			else
			{
				book[hang]=i;
				if (step+1==k) {ans++;}
				else if (hang<n-1)
				{
					dfs(step+1,hang+1);
					book[hang]=-1;
				}
				if (hang<n-1)
					dfs(step,hang+1);
			}
		}
	}
	return ;
}
int main()
{
	int i,j;
	while (scanf("%d%d",&n,&k)!=EOF)
	{
		if (n==-1&&k==-1) break;
		getchar();
		for (i=0;i<n;i++)
		gets(a[i]);//n*n
		ans=0;
		for (i=0;i<10;i++)
		book[i]=-1;
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;	
}