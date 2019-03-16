#include<stdio.h>
int a,b;
int book[200010];
struct note
{
	int k;
	int s;
}que[200010];
int tou,wei;
void dfs(int a)
{
	tou=wei=0;
	que[wei].k=a;
	que[wei].s=0;
	wei++;
	int aa;
	while (tou<wei)
	{
		aa=que[tou].k+1;
		if (aa>=0&&aa<200010&&book[aa]==0)
		{
			que[wei].k=aa;
			que[wei].s=que[tou].s+1;
			wei++;
			book[aa]=1;
			if (aa==b) return ;
		}
		aa=que[tou].k-1;
		if (aa>=0&&aa<200010&&book[aa]==0)
		{
			que[wei].k=aa;
			que[wei].s=que[tou].s+1;
			wei++;
			book[aa]=1;
			if (aa==b) return ;
		}
		aa=que[tou].k*2;
		if (aa>=0&&aa<200010&&book[aa]==0)
		{
			que[wei].k=aa;
			que[wei].s=que[tou].s+1;
			wei++;
			book[aa]=1;
			if (aa==b) return ;
		}
		tou++;
	}
	return ;
}
int main()
{
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		int i;
		for (i=0;i<200010;i++) book[i]=0;
		book[a]=1;
		dfs(a);
		printf("%d\n",que[wei-1].s);
	}
	return 0;
}