#include<bits/stdc++.h>
using namespace std;
struct node
{
	int s,l;
}que[120];
bool cmp(struct node q,struct node p)
{
	if (q.l==p.l) return q.s>p.s;
	return q.l<p.l;
}

int main()
{
	int n;
	while (scanf("%d",&n)!=EOF&&n)
	{
		for (int i=0;i<n;i++) scanf("%d%d",&que[i].s,&que[i].l);
		sort(que,que+n,cmp);
		int k=que[0].l;
		int sum=1;
		for (int i=1;i<n;i++)
		{
			if (k<=que[i].s)
			{
				k=que[i].l;
				sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}