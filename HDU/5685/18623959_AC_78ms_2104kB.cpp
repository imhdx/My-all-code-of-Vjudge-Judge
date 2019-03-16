#include<cstdio>
using namespace std;
const int mod=9973;
long long poww(long long a,long long b)
{
    long long res=1;
    while (b)
    {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
long long a[100010];
char str[100010];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF){
        scanf("%s",str);
        a[0]=1;
        for (int i=0;str[i];i++)
        {
            a[i+1]=a[i]*(str[i]-28)%9973;
        }
        for (int i=0;i<n;i++){
            int x,y;scanf("%d%d",&x,&y);
            long long ans=a[y]*poww(a[x-1],mod-2)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
