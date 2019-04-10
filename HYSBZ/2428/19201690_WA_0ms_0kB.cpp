///hzwer.com
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<ctime>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define ll long long
#define pa pair<int,int>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
double ave,ans,mn=1e30;
int n,m,K;
int a[25];
int pos[25];
double sum[25];
void solve()
{
	memset(sum,0,sizeof(sum));
	ans=0;
    for(int i=1;i<=n;i++)
		pos[i]=rand()%m+1;
	for(int i=1;i<=n;i++)
		sum[pos[i]]+=a[i];
	for(int i=1;i<=m;i++)
		ans+=(sum[i]-ave)*(sum[i]-ave);
	double T=10000;
	while(T>0.1)
	{
		T*=0.9;
		int t1=rand()%n+1,x=pos[t1],y;
		if(T>500)y=min_element(sum+1,sum+m+1)-sum;
		else y=rand()%m+1;
		if(x==y)continue;
		double pre=ans;
		ans-=(sum[x]-ave)*(sum[x]-ave);
		ans-=(sum[y]-ave)*(sum[y]-ave);
		sum[x]-=a[t1];sum[y]+=a[t1];
		ans+=(sum[x]-ave)*(sum[x]-ave);
		ans+=(sum[y]-ave)*(sum[y]-ave);
		if(rand()%10000>T&&ans>pre)
		{
			sum[x]+=a[t1];sum[y]-=a[t1];
			ans=pre;
		}
		else pos[t1]=y;
	}
	if(ans<mn)mn=ans;
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		ave+=a[i];
		swap(a[i],a[rand()%i+1]);
	}
	ave/=m;
	for(int i=1;i<=10000;i++)solve();
	printf("%.2f",sqrt(mn/m));
	return 0;
}