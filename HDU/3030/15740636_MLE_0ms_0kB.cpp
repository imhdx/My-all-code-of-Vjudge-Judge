#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
int bit[5000010];
int a[5000010];
const int mod=1e9+7;
void add(int x,int w)
{
    while (x<500010)
    {
        bit[x]=((bit[x]+w)%mod+mod)%mod;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int s=0;
    while (x>0)
    {
        s=((s+bit[x])%mod+mod)%mod;
        x-=lowbit(x);
    }
    return s;
}
int main()
{
    int t=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        memset(bit,0,sizeof(bit));
        int n,m,x,y,z;
        scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
        for (int i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<n;i++)
        {
            //printf("%d\n",a[i%m]);
            int temp=ask(a[i%m]);
            //printf("i=%d temp=%d\n",i,temp);
            add(a[i%m]+1,temp+1);
            a[i%m]=((1ll*x%z*a[i%m]%z+y%z*(i+1)%z)%z+z)%z;
        }
        printf("Case #%d: ",t++);
        //printf("hi\n");
        printf("%d\n",ask(500010));
    }
    return 0;
}
