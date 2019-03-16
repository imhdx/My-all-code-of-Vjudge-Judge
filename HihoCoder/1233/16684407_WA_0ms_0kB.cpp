#include<bits/stdc++.h>
using namespace std;
map<int,int> M;
int f(int a,int b,int c)
{
	if (a>b&&a>c&&b>c) return 4*5;
	else if (a>b&&a>c&&b<c) return 4*4;
	else if (b>a&&b>c&&a<c) return 3*4;
	else if (b>a&&b>c&&a>c) return 2*4;
	else if (c>a&&c>b&&a>b) return 4;
	else return 0;
}
int a[10];
int n;
struct node
{
	int s;
	int q[10];
	/*
	bool operator<(const node &ppp) const
	{
		return s>ppp.s;
	}
	*/
};

bool check(int s[10])
{
	for (int i=0;i+1<n;i++)
	{
		if (s[i]>s[i+1]) return false;
	}
	return true;
}

int bfs()
{
	queue<node> que; 
	struct node pp;
	pp.s=0;
	int qwe=0;
	for (int j=0;j<n;j++) qwe=qwe*10+a[j];
	M[qwe]=1;
	for (int i=0;i<n;i++) pp.q[i]=a[i];
	que.push(pp);
	struct node tt=que.back();
	if (check(tt.q))
	{
		return tt.s;
	}
	while (!que.empty())
	{
		struct node tt=que.front();
		que.pop();
		int g[10];
		for (int i=0;i+2<n;i++)
		{
			for (int j=0;j<n;j++) g[j]=tt.q[j];
			int ans=tt.s+f(g[i],g[i+1],g[i+2]);
			//printf("ans=%d\n",ans);
			sort(g+i,g+i+3);
			int qwe=0;
			for (int j=0;j<n;j++) qwe=qwe*10+g[j];
			if (M[qwe]) continue;
			M[qwe]=1;
			//for (int kk=0;kk<n;kk++) printf("%d%c",g[kk]," \n"[kk==n-1]);
			struct node pp;
			pp.s=ans;
			for (int j=0;j<n;j++) pp.q[j]=g[j]; 
			que.push(pp);
			if (check(pp.q))
			{
				return pp.s;
			}
		}
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		M.clear();
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		if (n<2)
		{
			printf("0\n");
			continue;
		}
		if (n==2)
		{
			if (a[0]<a[1]) printf("0\n");
			else printf("-1\n");
			continue;
		}
		/*
		long long int ans=0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j+2<n;j++)
			{
				ans+=f(a[j],a[j+1],a[j+2]);
				sort(a+j,a+j+3);
				for (int k=0;k<n;k++)
				printf("%d%c",a[k]," \n"[k==n-1]);
			}
		}
		*/
		printf("%d\n",bfs());
	}
	return 0;
}
