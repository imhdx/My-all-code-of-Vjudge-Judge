#include<cstdio>
#include<algorithm>
using namespace std;
struct note
{
	int l,w;
}mu[5010];
int book[5010];
bool cmp(note aa,note bb)
{
	if (aa.l==bb.l) return aa.w>=bb.w;
	return aa.l>bb.l;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int i,n,j;
		for (i=0;i<5010;i++) book[i]=0;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&mu[i].l,&mu[i].w);
		}
		sort(mu,mu+n,cmp);
		int ans=0;
		int max;
		int anss=0;
		while (ans!=n)
		{
			for (i=0;i<n;i++)
			{
				if (book[i]==0)
				{
					ans++;
					max=i;
					book[i]=1;
					break;
				}
			}
			for (i=max+1;i<n;i++)
			{
				if (book[i]==0&&mu[max].l>=mu[i].l&&mu[max].w>=mu[i].w)
				{
					book[i]=1;
					ans++;
					max=i;
				}
			}
			anss++;
		}
		printf("%d\n",anss);
	}
	return 0;
}
