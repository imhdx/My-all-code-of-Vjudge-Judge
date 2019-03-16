#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
int s,n,m;
int mid;
int ans=0;
int flag=0;
int book[105][105][105]={0};
struct note
{
	int s,n,m;
	int bu;
}que[9999999];
int tou,wei;
void dfs(int ss,int nn,int mm)
{
	tou=wei=0;
	int i,j;
	que[wei].s=ss;
	que[wei].n=nn;
	que[wei].m=mm;
	que[wei].bu=0;
	wei++;
	while (tou<wei)
	{
		int ts;
		int tn;
		int tm;
		if (que[tou].s<s)
		{
			if (que[tou].n>0)
			{
				ts=que[tou].s+((que[tou].s+que[tou].n)>s?(s-que[tou].s):que[tou].n);
				tn=que[tou].n-((que[tou].s+que[tou].n)>s?(s-que[tou].s):que[tou].n);
				tm=que[tou].m;
				if (book[ts][tn][tm]==0)
				{
					que[wei].s=ts;
					que[wei].n=tn;
					que[wei].m=tm;
					que[wei].bu=que[tou].bu+1;
					wei++;
					book[ts][tn][tm]=1;
					if (que[wei-1].s==0&&que[wei-1].n==mid&&que[wei-1].m==mid||
                        que[wei-1].s==mid&&que[wei-1].n==mid&&que[wei-1].m==0||
                        que[wei-1].s==mid&&que[wei-1].n==0&&que[wei-1].m==mid
                        )
					{
						flag=1;
						return ;
					}
				}
			}
			if (que[tou].m>0)
			{
				ts=que[tou].s+((que[tou].m+que[tou].s)>s?(s-que[tou].s):que[tou].m);
				tm=que[tou].m-((que[tou].m+que[tou].s)>s?(s-que[tou].s):que[tou].m);
				tn=que[tou].n;
				if (book[ts][tn][tm]==0)
				{
					que[wei].s=ts;
					que[wei].n=tn;
					que[wei].m=tm;
					que[wei].bu=que[tou].bu+1;
					wei++;
					book[ts][tn][tm]=1;
					if (que[wei-1].s==0&&que[wei-1].n==mid&&que[wei-1].m==mid||
                        que[wei-1].s==mid&&que[wei-1].n==mid&&que[wei-1].m==0||
                        que[wei-1].s==mid&&que[wei-1].n==0&&que[wei-1].m==mid
                        )
					{
						flag=1;
						return ;
					}
				}
			}
		}
		if (que[tou].n<n)
		{
			if (que[tou].s>0)
			{
				tn=que[tou].n+((que[tou].s+que[tou].n)>n?(n-que[tou].n):que[tou].s);
				ts=que[tou].s-((que[tou].s+que[tou].n)>n?(n-que[tou].n):que[tou].s);
				tm=que[tou].m;
				if (book[ts][tn][tm]==0)
				{
					que[wei].s=ts;
					que[wei].n=tn;
					que[wei].m=tm;
					que[wei].bu=que[tou].bu+1;
					wei++;
					book[ts][tn][tm]=1;
					if (que[wei-1].s==0&&que[wei-1].n==mid&&que[wei-1].m==mid||
                        que[wei-1].s==mid&&que[wei-1].n==mid&&que[wei-1].m==0||
                        que[wei-1].s==mid&&que[wei-1].n==0&&que[wei-1].m==mid
                        )
					{
						flag=1;
						return ;
					}
				}
			}
			if (que[tou].m>0)
			{
				tn=que[tou].n+((que[tou].m+que[tou].n)>n?(n-que[tou].n):que[tou].m);
				tm=que[tou].m-((que[tou].m+que[tou].n)>n?(n-que[tou].n):que[tou].m);
				ts=que[tou].s;
				if (book[ts][tn][tm]==0)
				{
					que[wei].s=ts;
					que[wei].n=tn;
					que[wei].m=tm;
					que[wei].bu=que[tou].bu+1;
					wei++;
					book[ts][tn][tm]=1;
					if (que[wei-1].s==0&&que[wei-1].n==mid&&que[wei-1].m==mid||
                        que[wei-1].s==mid&&que[wei-1].n==mid&&que[wei-1].m==0||
                        que[wei-1].s==mid&&que[wei-1].n==0&&que[wei-1].m==mid
                        )
					{
						flag=1;
						return ;
					}
				}
			}
		}
		if (que[tou].m<m)
		{
			if (que[tou].s>0)
			{
				tm=que[tou].m+((que[tou].s+que[tou].m)>m?(m-que[tou].m):que[tou].s);
				ts=que[tou].s-((que[tou].s+que[tou].m)>m?(m-que[tou].m):que[tou].s);
				tn=que[tou].n;
				if (book[ts][tn][tm]==0)
				{
					que[wei].s=ts;
					que[wei].n=tn;
					que[wei].m=tm;
					que[wei].bu=que[tou].bu+1;
					wei++;
					book[ts][tn][tm]=1;
					if (que[wei-1].s==0&&que[wei-1].n==mid&&que[wei-1].m==mid||
                        que[wei-1].s==mid&&que[wei-1].n==mid&&que[wei-1].m==0||
                        que[wei-1].s==mid&&que[wei-1].n==0&&que[wei-1].m==mid
                        )
					{
						flag=1;
						return ;
					}
				}
			}
			if (que[tou].n>0)
			{
				tm=que[tou].m+((que[tou].n+que[tou].m)>m?(m-que[tou].m):que[tou].n);
				tn=que[tou].n-((que[tou].n+que[tou].m)>m?(m-que[tou].m):que[tou].n);
				ts=que[tou].s;
				if (book[ts][tn][tm]==0)
				{
					que[wei].s=ts;
					que[wei].n=tn;
					que[wei].m=tm;
					que[wei].bu=que[tou].bu+1;
					wei++;
					book[ts][tn][tm]=1;
					if (que[wei-1].s==0&&que[wei-1].n==mid&&que[wei-1].m==mid||
                        que[wei-1].s==mid&&que[wei-1].n==mid&&que[wei-1].m==0||
                        que[wei-1].s==mid&&que[wei-1].n==0&&que[wei-1].m==mid
                        )
					{
						flag=1;
						return ;
					}
				}
			}
		}
		tou++;
		if (flag==1) return ;
	}
	return ;
}
int main()
{
	while (scanf("%d%d%d",&s,&n,&m)!=EOF)
	{
	    if (s==0&&n==0&&m==0) return 0;
		int i,j,k;
		for (i=0;i<105;i++)
		for (j=0;j<105;j++)
		for (k=0;k<105;k++)
		book[i][j][k]=0;
		book[s][0][0]=1;
		ans=0;
		flag=0;
		mid=s/2;
		dfs(s,0,0);
		if (flag==0) printf("NO\n");
		else
		printf("%d\n",que[wei-1].bu);

	}
	return 0;
}
