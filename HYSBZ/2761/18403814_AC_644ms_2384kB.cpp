#include<cstdio>
const int N=100007;
const int INF=0x3f3f3f3f;
inline int abs(int v)
{
    return v<0?-v:v;
}
struct Hash_Set
{
    int tot,head[N],next[N<<1],arr[N];
    inline void init()
    {
        tot=0;
        for (int i=0;i<N;i++) head[i]=-1;
    }
    inline bool insert(int v)
    {
        int u=abs(v)%N;
        for (int i=head[u];~i;i=next[i])
        {
            if (arr[i]==v) return false;
        }
        arr[tot]=v;next[tot]=head[u];head[u]=tot++;
        return true;
    }
}hash;
int main()
{
    int t,v,n;
    scanf("%d",&t);
    while (t--)
    {
        hash.init();
        scanf("%d%d",&n,&v);
        printf("%d",v);
        hash.insert(v);
        for (int i=0;i<n-1;i++)
        {
            scanf("%d",&v);
            if (hash.insert(v)) printf(" %d",v);
        }
        printf("\n");
    }
}
