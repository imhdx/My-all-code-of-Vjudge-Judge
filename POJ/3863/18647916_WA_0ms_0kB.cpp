#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int inf=1e9+7;
typedef long long ll;
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
int solve(int u,int v)
{
    int l=0,r=n;
    int ans=inf;
    while (l<=r){
        int mid=l+r>>1;
        int t=u*mid-(n-mid)*v;
        if (t>=0){
            ans=t;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int main()
{
    n=read();m=read();
    int ans=inf;
    for (int i=1;i<=m;i++){
        int u=read(),v=read();
        ans=min(ans,solve(u,v));
    }
    printf("%d\n",ans);
    return 0;
}
