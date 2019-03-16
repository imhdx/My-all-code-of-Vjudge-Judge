#include<cstdio>
#include<algorithm>
using namespace std;
int a[600];
int b[600];
int c[600];
int d[600];
int main()
{
	int q,w,e;
	int qwe=1;
	while (scanf("%d%d%d",&q,&w,&e)!=EOF)
	{
		int i,j,k=0;
		for (i=0;i<q;i++)
		scanf("%d",&a[i]);
		for (i=0;i<w;i++)
		{
			scanf("%d",&b[i]);
			for (j=0;j<q;j++)
			d[k++]=a[j]+b[i];
		}
		sort(d,d+k);
		for (i=0;i<e;i++)
		scanf("%d",&c[i]);
		int t;
		scanf("%d",&t);
		printf("Case :%d\n",qwe);
		while (t--)
		{
			int xx;
			scanf("%d",&xx);
			int flag=0;
			for (i=0;i<e;i++)
			{
				if (xx-c[i]<d[0]||xx-c[i]>d[k-1]) continue;
				int mid;
				int st=0;
				int la=k-1;
				while (st<la)
				{
					mid=(la+st)/2;
					if (c[i]+d[mid]==xx) {flag=1;break;}
					else if (c[i]+d[mid]<xx) st=mid;
					else la=mid;
				}
				if (flag==1) break;
			}
			qwe++;
			if (flag==1) printf("YES\n");
			else
			printf("NO\n");
		}		
	}
	return 0;
}