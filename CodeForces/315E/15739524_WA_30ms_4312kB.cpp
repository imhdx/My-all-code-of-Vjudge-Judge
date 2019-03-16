#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
int d[100010];
int bit[1000010];
const int mod=1e9+7;
void add(int x,int w)
{
    while (x<1000010)
    {
        bit[x]+=w%mod;
        x+=lowbit(x);
    }
}
int ask(int x)
{
    int s=0;
    while (x>0)
    {
        s+=bit[x]%mod;
        x-=lowbit(x);
    }
    return s;
}
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        int temp=(1ll*ask(x)*x%mod+x)%mod;
        add(x,temp-d[x]);
        //printf("%d %d\n",x,d[x]);
        d[x]=temp;
    }
    printf("%d\n",ask(1000009));
    return 0;
}
