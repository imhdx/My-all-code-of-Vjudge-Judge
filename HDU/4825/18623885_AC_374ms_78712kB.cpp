#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t[6600010][3];
int sz=0;
void insert(long long n)
{
    int flag=0;
    int now=0;
    for (int i=33;i>=0;i--){
        int k=(n>>i)&1;
        if (t[now][k]==0)
        {
            t[now][k]=++sz;
        }
        now=t[now][k];
    }
}
long long ask(long long n)
{
    long long ans=0;
    int now=0;
    for (int i=33;i>=0;i--){
        int k=(n>>i)&1;
        if (t[now][k^1])
        {
            now=t[now][k^1];
            if ((k^1)==1) ans+=(1ll<<i);
        }
        else{
            now=t[now][k];
            if ((k)==1) ans+=(1ll<<i);
        }
    }
    return ans;
}
int main()
{
    int tt=1;
    int T;scanf("%d",&T);
    while (T--)
    {
        sz=0;
        memset(t,0,sizeof(t));
        int n;scanf("%d",&n);
        int m;scanf("%d",&m);
        for (int i=0;i<n;i++){
            long long x;scanf("%lld",&x);
            insert(x);
        }
        printf("Case #%d:\n",tt++);
        for (int i=0;i<m;i++){
            long long x;scanf("%lld",&x);
            printf("%lld\n",ask(x));
        }
    }

    return 0;
}
