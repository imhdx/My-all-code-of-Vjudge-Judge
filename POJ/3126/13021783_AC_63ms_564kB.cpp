#include<math.h>
#include<stdio.h>
int a,b;
int prime[10010];
int book[10010];
int tou,wei;
struct note
{
	int num;
	int s;
}que[20010];
int pri(int q)
{
	for (int i=2;i<=(int)sqrt(q);i++)
	if (q%i==0) return 0;
	return 1;
}
void dfs(int a)
{
	tou=wei;
	que[wei].num=a;
	que[wei].s=0;
	wei++;
	if (a==b) return ;
	while (tou<wei)
	{
		int aa;
		for (int i=0;i<4;i++)
		{
			aa=que[tou].num-que[tou].num%(int)pow(10,i+1)+que[tou].num%(int)pow(10,i);
			for (int j=0;j<10;j++)
			{
				int aaa=aa+j*(int)pow(10,i);
				if (aaa==que[tou].num||aaa<1000||aaa>9999||book[aaa]==1||prime[aaa]==0) continue;
				book[aaa]=1;
				que[wei].num=aaa;
				que[wei].s=que[tou].s+1;
				wei++;
				if (aaa==b) return ;
			}
		}
		tou++;
	} 
	return ;
}
int main()
{
	int i;
	int ttt;
	for (i=1000;i<=9999;i++)
	{
		prime[i]=pri(i);
	}
	scanf("%d",&ttt);
	while (ttt--)
	{
		scanf("%d%d",&a,&b);
		for (i=0;i<10010;i++) book[i]=0;
		book[a]=1;
		
		dfs(a);
		printf("%d\n",que[wei-1].s);
	}
	return 0;
}