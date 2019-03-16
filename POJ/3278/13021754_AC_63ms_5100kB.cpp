#include<stdio.h>
long long int a,b;
long long int book[200010];
struct note
{
	long long int k;
	long long int s;
}que[200010];
long long int tou,wei;
void dfs(long long int a)
{
	tou=wei=0;
	que[wei].k=a;
	que[wei].s=0;
	wei++;
	long long int aa;
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
	while (scanf("%lld%lld",&a,&b)!=EOF)
	{
		if (a==b) {printf("0\n");continue;}
		int i;
		for (i=0;i<200010;i++) book[i]=0;
		book[a]=1;
		dfs(a);
		printf("%lld\n",que[wei-1].s);
	}
	return 0;
}