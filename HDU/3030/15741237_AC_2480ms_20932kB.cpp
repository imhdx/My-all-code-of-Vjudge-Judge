#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
long long bit[500011];
long long a[500010];
long long mapid[500010];
const int mod=1e9+7;
struct node
{
    long long x;
    int id;
}node[500010];
bool cmp(struct node q,struct node p)
{
    return q.x<p.x;
}
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
        long long int n,m,x,y,z;
        scanf("%d%d%d%d%d",&n,&m,&x,&y,&z);
        for (int i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=0;i<n;i++)
        {
            node[i].x=a[i%m];
            node[i].id=i+1;
            a[i%m]=((1ll*x%z*a[i%m]%z+y%z*(i+1)%z)%z+z)%z;
        }
        /*
        for (int i=0;i<n;i++)
        {
            printf("%d%c",node[i].x," \n"[i==n-1]);
        }
        */
        sort(node,node+n,cmp);
        int cnt=2;
        mapid[node[0].id]=cnt;
        for (int i=1;i<n;i++)
        {
            if (node[i].x==node[i-1].x)
            {
                mapid[node[i].id]=cnt;
            }
            else
            {
                cnt++;
                mapid[node[i].id]=cnt;
            }
        }
        /*
        for (int i=0;i<n;i++)
        {
            printf("%d%c",mapid[i]," \n"[i==n-1]);
        }
        */
        for (int i=1;i<=n;i++)
        {
            add(mapid[i],ask(mapid[i]-1)+1);
        }
        printf("Case #%d: ",t++);
        //printf("hi\n");
        printf("%d\n",ask(500010));
    }
    return 0;
}
