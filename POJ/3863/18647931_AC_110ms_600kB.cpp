#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define mod 1000000007
#define inf 1000000000
#define pi acos(-1)
#define ll long long
#define p(x,y) (x-1)*m+y
using namespace std;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int solve(int a,int b)
{
	int l=0,r=n,ans=inf,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		int t=mid*a-(n-mid)*b;
		if(t>0)ans=t,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main()
{
	n=read();m=read();
	int ans=inf;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		ans=min(solve(u,v),ans);
	}
	printf("%d\n",ans);
	return 0;
}
